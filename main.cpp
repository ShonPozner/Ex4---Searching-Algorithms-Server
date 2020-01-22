#include <iostream>
#include <queue>
#include <fstream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "SearcherAdapter.h"
#include "FileCacheManger.h"
#include "StringReverser.h"
#include "MatrixSearchProblem.h"
#include "BestFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "Dfs.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
#include "Astar.h"

using namespace std;
static void testAllAlgorithms();


namespace boot
{

/**
 * Main class.
 * Allows three different actions depending on the login argument :
 *      1- Execution of Task 2 - Reverse the order of letters
 *      2- Creates a file of tests for the various algorithms used in the exercise
 *      3 - Running a parallel server and solve the matrix search
 */
  class Main {
   public:
    //Execution of Task 2 - Reverse the order of letters
    int main_part2(int port) {
      CacheManager<string, string> *cacheManager = new FileCacheManger();
      Solver<string,string> *slover = new StringReverser();
      ClientHandler *clientHand = new MyTestClientHandler(cacheManager,slover);
      Server *server = new MySerialServer();
      server->open(port,clientHand);
      return 0;
    }

    // Running a parallel server and solve the matrix search
    int main(int port) {

      Searcher<Cell*> *best = new Astar<Cell*>();
      Solver<Searchable<Cell*>*,vector<State<Cell*>*>> *slover1 = new SearcherAdapter<Cell*>(best);
      CacheManager<string, string> *cacheManager = new FileCacheManger();
      ClientHandler *cm = new MyClientHandler(slover1,cacheManager);
      Server *server = new MyParallelServer();
      server->open(port,cm);
      return 0;
    }

    //Creates a file of tests for the various algorithms used in the exercise
    void testAlgo() {
      testAllAlgorithms();
    }
  };
}

using namespace boot;

/**
 * main class.
 *  Chooses what to run based on the argumet we received -
 *      if we get "testAlgo" - do test algorithms
 *     if we get port - does main -Running a parallel server and solve the matrix search
 *     if we get port and  "part2" - dpes Task 2 - Reverse the order of letters
 */
int main (int argc, char *argv[]){
  Main m;
  if(argc >= 2) {
    string str = argv[1];
    if(!str.compare("testAlgo")) {
      m.testAlgo();
      return 0;
    } else if(argc == 2) {
      int port = stoi(argv[1]);
      m.main(port);
    } else if(argc ==3) {
      str = argv[2];
      if (!str.compare("part2")) {
        m.main_part2(stoi(argv[1]));
      }
    }
    } else {
    cout<<"the arguments not valid pleas try again";
  }

  return 0;
}

// build matrix remove spaces and spite lines and make str to nums
static void buildMatrix(vector<vector<int>> &matrix, string line) {
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

// creat a vectot of num
static void txtToVec(vector<vector<int>> &vecTest3, string name) {
  name = "Matrix_Problem/" + name;
  ifstream infile(name);
  if (infile.good()) {
    string line;
    std::vector<std::string> splittedStrings;
    while (getline(infile, line)) {
      splittedStrings.push_back(line);
    }
    while (!splittedStrings.empty()) {
      if (splittedStrings.front() == "end" || splittedStrings.front() == "End") {
        break;
      } else {
        buildMatrix(vecTest3, splittedStrings.front());
      }
      splittedStrings.erase(splittedStrings.begin());
    }
  } else {
    cout<<"bed name";
  }
}

// Creat a 4  Algorithms and run 11 matrix
static void testAllAlgorithms() {
  vector<State<Cell*>*> result;
  ofstream Outfile("ResultOfTest.txt");
  if (Outfile.good()) {
    cout<<"new file of the Result - ResultOfTest.txt \n";
    Outfile<<"Start the test:\n";
  } else {
    throw "Error opening file\n\n";
  }

  Outfile<<"\nStart BestFirstSearch: \n";
  int counter = 1;
  for(int i = 10; i<51;i+=4) {
    string name = "Matrix_" + to_string(i)+".txt";
    vector<vector<int>> vecTest1;
    txtToVec(vecTest1,name);

    Searcher<Cell*> *best1 = new BestFirstSearch<Cell*>();
    Searchable<Cell*> *max1 = new MatrixSearchProblem(vecTest1);

    vector<State<Cell*>*>  c1 =best1->search(max1);
    Outfile<<"Matrix number: "+ to_string(counter) +" size of: " + to_string(i)+ "X" + to_string(i);
    Outfile<<" -  "<<best1->getNumberOfStateEvaluated()<<"\n";
  }

  Outfile<<"\nStart A star: \n";
  counter = 1;
  for(int i = 10; i<51;i+=4) {
    string name = "Matrix_" + to_string(i)+".txt";
    vector<vector<int>> vecTest1;
    txtToVec(vecTest1,name);

    Searcher<Cell*> *best1 = new Astar<Cell*>();
    Searchable<Cell*> *max1 = new MatrixSearchProblem(vecTest1);

    vector<State<Cell*>*>  c1 =best1->search(max1);
    Outfile<<"Matrix number: "+ to_string(counter) +" size of: " + to_string(i)+ "X" + to_string(i);
    Outfile<<" -  "<<best1->getNumberOfStateEvaluated()<<"\n";
  }


  Outfile<<"\nStart Dfs: \n";
  counter = 1;
  for(int i = 10; i<51;i+=4) {
    string name = "Matrix_" + to_string(i)+".txt";
    vector<vector<int>> vecTest3;
    txtToVec(vecTest3,name);

    Searcher<Cell*> *best3 = new Dfs<Cell*>();
    Searchable<Cell*> *max3 = new MatrixSearchProblem(vecTest3);

    vector<State<Cell*>*>  c3 =best3->search(max3);
    Outfile<<"Matrix number: "+ to_string(counter) +" size of: " + to_string(i)+ "X" + to_string(i);
    Outfile<<" -  "<<best3->getNumberOfStateEvaluated()<<"\n";
  }

  Outfile<<"\nStart Breadth First Search: \n";
  counter = 1;
  for(int i = 10; i<51;i+=4) {
    string name = "Matrix_" + to_string(i)+".txt";
    vector<vector<int>> vecTest2;
    txtToVec(vecTest2,name);

    Searcher<Cell*> *best2 = new BreadthFirstSearch<Cell*>();
    Searchable<Cell*> *max2 = new MatrixSearchProblem(vecTest2);

    vector<State<Cell*>*>  c2 =best2->search(max2);
    Outfile<<"Matrix number: "+ to_string(counter) +" size of: " + to_string(i)+ "X" + to_string(i);
    Outfile<<" -  "<<best2->getNumberOfStateEvaluated()<<"\n";
  }
  Outfile.close();
  return;

}


