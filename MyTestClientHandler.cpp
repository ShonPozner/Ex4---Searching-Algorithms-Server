//
// Created by shon on 11.1.2020.
//

#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>
#include <sstream>
#include "MyTestClientHandler.h"


void MyTestClientHandler::handleClient(int clientSocket) {
  char msg[MAXPACKETSIZE];
  memset(msg, 0, MAXPACKETSIZE);
  std::vector<std::string> splittedStrings;
  do {
    bool stop = false;
    int checkLineReade =read(clientSocket, &msg, MAXPACKETSIZE);
    if (checkLineReade == -1 ){
      puts("error in read line of string from the clinet\n");
      close(clientSocket);
      break;
    } else {

      stringstream msgStr(msg);
      string item;

      while (getline(msgStr,item,'\r')){
        if(item=="\n") {
          continue;
        }
        int dot = item.find('\n'); {
          if (dot>=0 && dot<item.length()+1) {
            item.erase(dot,1);
          }
        }
        splittedStrings.push_back(item);
      }

      while (!splittedStrings.empty()) {
        if (splittedStrings.front() == "end" || splittedStrings.front() == "End") {
          stop = true;
          break;
        } else {
          string solution = getSolution(splittedStrings.front());
          solution = solution + '\n';
          cout << splittedStrings.front() << endl;
          int testSend = send(clientSocket, solution.c_str(), solution.size(), 0);
          if (testSend == -1) {
            puts("error in send massage\n");
            exit(1);
          }
        }
        splittedStrings.erase(splittedStrings.begin());
      }
      if(stop){
        break;
      }

      for (int i = 0; i < 1024; i++) {
        msg[i] = 0;
      }
    }
  }
  while (true);
}


string MyTestClientHandler::getSolution(string fixMsg){
  if (this->_cacheManager->isExist(fixMsg)) {
    return this->_cacheManager->findSolution(fixMsg);
  } else {
    string solution= this->_solver->solve(fixMsg);
    _cacheManager->addToCache(fixMsg,solution);
    return solution;
  }
}


string MyTestClientHandler::fixLine(string msg){
  char test = msg[msg.length()-1];
  string fixMsg = msg;
  while (test == '\n' || test == '\r') {
    fixMsg = fixMsg.substr(0, fixMsg.size() - 1);
    test = fixMsg[fixMsg.size() - 1];
  }
  return fixMsg;
}

MyTestClientHandler::MyTestClientHandler(CacheManager<string, string> *cacheMan, Solver<string, string> *solver) {
  _solver = solver;
  _cacheManager =cacheMan;
}
ClientHandler *MyTestClientHandler::getClone() {
  return new MyTestClientHandler(this->_cacheManager->getClone(),this->_solver->getClone());
}

