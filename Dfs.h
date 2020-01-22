//
// Created by shon on 18.1.2020.
//

#ifndef EX4_SEARCH_ALGORITHMS_DFS_H_
#define EX4_SEARCH_ALGORITHMS_DFS_H_
#include "AbstractSearcher.h"
#include <stack>
using namespace std;

/**
 * Dfs class.
 * sort a Deep First Search white a set and Stack
 * every time go to next node
 */

template <class T>
class Dfs: public AbstractSearcher<T>  {


 public:

  Dfs():AbstractSearcher<T>(){};
  ~Dfs() = default;

  vector<State<T>*> search(Searchable<T>* searchable);

  // Creating deep clone of the object
  Searcher<T>* getClone() {
    return new Dfs<T>();
  }

};


template<class T>
vector<State<T> *> Dfs<T>::search(Searchable<T> *searchable) {
  vector<State<T>*> successors;
  stack<State<T>*> stackDFS;
  //push to the queueDfs the initial state
  stackDFS.push(searchable->getInitialState());
  //while ( Q is not empty)
  while(!stackDFS.empty()) {
    //Pop a vertex from stack to visit next
    State<T>* v = stackDFS.top();
    stackDFS.pop();
    this->_evaluatedNodes++;
    // Checking if n is a Goal state if return the back Trace
    if (searchable->isGoalState(v)) {
      return this->traceBack(v);
    }
    if (!this->isInClosedList(v)) {
      this->_setClose.insert(v);
      //processing all the neighbours of v
      successors =searchable->getAllPossibleStates(v);
      //for all neighbours w of v in Graph
      for(State<T>* w : successors) {
        if (!this->isInClosedList(w)) {
          w->setCameFrom(v);
          w->setCost(w->getCost()+ v->getCost());
          stackDFS.push(w);
        }
      }
    }
  }
  cerr << "error: cannot get the goal state" << endl;
  exit(1);
}

#endif //EX4_SEARCH_ALGORITHMS_DFS_H_
