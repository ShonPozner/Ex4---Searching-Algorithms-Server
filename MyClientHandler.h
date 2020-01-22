//
// Created by shon on 19.1.2020.
//

#ifndef EX4_CLIENTHANDLE_MYCLIENTHANDLER_H_
#define EX4_CLIENTHANDLE_MYCLIENTHANDLER_H_

#include <cstring>
#include <unistd.h>
#include <sstream>
#include <sys/socket.h>
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "Searchable.h"
#include "Cell.h"
#include "Utils.h"
#include "MatrixSearchProblem.h"

#define MAXPACKETSIZE 2048

/**
 * MyClientHandler class
 * Useing solver and cacheManager to get Solution of Problem
 */


class MyClientHandler: public ClientHandler {
 private:
  //problem string -> Searchbale<cell>* , solusion vector<State<T>*->string
  Solver<Searchable<Cell*>*,vector<State<Cell*>*>> *_solver;
  CacheManager<string, string> *_cacheManager;


 public:

  ClientHandler* getClone(){
    return new MyClientHandler(this->_solver->getClone(), this->_cacheManager->getClone());
  }


  MyClientHandler(Solver<Searchable<Cell*>*,vector<State<Cell*>*>> *solver, CacheManager<string,string> *cacheMan) {
    _solver = solver;
    _cacheManager =cacheMan;
  }

  ~MyClientHandler() override {
    delete _solver;
  }

  void handleClient(int clientSocket) override;


  void buildMatrix(vector<vector<int>> &matrix, string line) {
    //remove spaces on each line
    line = Utils::removeSpaces(line);

    //split the ',' in the line each str to cell
    vector<string> str = Utils::splitStr(line,",");

    //making the str to int
    vector<int> temp;
    for (auto &s : str) {
      std::stringstream parser(s);
      int x = 0;
      parser >> x;
      temp.push_back(x);
    }
    matrix.push_back(temp);

  }




};
void MyClientHandler::handleClient(int clientSocket) {
  char msg[MAXPACKETSIZE];
  memset(msg, 0, MAXPACKETSIZE);
  vector<vector<int>> matrixVec;
  std::vector<std::string> splittedStrings;
  do {
    bool stop = false;
    int checkLineReade = read(clientSocket, &msg, MAXPACKETSIZE);
    if (checkLineReade == -1) {
      puts("error in read line of string from the clinet\n");
      close(clientSocket);
      break;
    } else {

      stringstream msgStr(msg);
      string item;
      while (getline(msgStr, item, '\r')) {
        if (item == "\n") {
          continue;
        }
        unsigned int dot = item.find('\n');
        {
          if (dot <= item.length()) {
            item.erase(dot, 1);
          }
        }
        splittedStrings.push_back(item);
      }
      while (!splittedStrings.empty()) {
        if (splittedStrings.front() == "end" || splittedStrings.front() == "End") {
          stop = true;
          break;
        } else {
          buildMatrix(matrixVec, splittedStrings.front());
        }
        splittedStrings.erase(splittedStrings.begin());
      }
      if (stop) {
        break;
      }
      for (int i = 0; i < MAXPACKETSIZE; i++) {
        msg[i] = 0;
      }
    }
  }
  while (true);
  string solution;
  Searchable<Cell*>* searchable;
  searchable = new MatrixSearchProblem(matrixVec);
  string nameProblem = searchable->getString();

  // Check if problem exist in cache, if not, solve it
  if (_cacheManager->isExist(nameProblem))
  {
    // Get solution from cache
    solution = this->_cacheManager->findSolution(nameProblem);
  } else if(matrixVec[0][0] == -1) {
    solution = "no solution start with -1"; 
   } else {
    vector<State<Cell*>*> vecCell = _solver->solve(searchable);
    solution = Utils::buildSolution(vecCell);
    this->_cacheManager->addToCache(nameProblem,solution);
  }
  solution =solution +"\n";
  delete searchable;
  int testSend = send(clientSocket, solution.c_str(), solution.size(), 0);
  if (testSend == -1) {
    puts("error in send massage\n");
    exit(1);
  }

}


#endif //EX4_CLIENTHANDLE_MYCLIENTHANDLER_H_
