//
// Created by shon on 17.1.2020.
//

#ifndef EX4_SEARCH_ABSTRACTSEARCHER_H_
#define EX4_SEARCH_ABSTRACTSEARCHER_H_

#include <iostream>
#include <queue>
#include <set>
//#include "Searcher.h"
#include "../Miscellaneous/StateCompare.h"
#include "../Miscellaneous/CellComper.h"



using namespace std;

template <class T>
class AbstractSearcher: public Searcher<T> {

 protected:
  priority_queue<State<T>* ,vector<State<T>*>, StateCompare<T>> _priorityQueue;
  set<State<T>*> _setClose;

  // get a next state from the priority queue and remove the first on the queue
  State<T>* popPriorityQueue() {
    this->_evaluatedNodes++;
    State<T>* state = _priorityQueue.top();
    //this->_searchCost += state->getCost();
    _priorityQueue.pop();
    return state;
  }

 public:
  //Constructor
  AbstractSearcher(): Searcher<T>(0,0) {}

  // return the size of the priority queue
  int OpenListSize() {
    return _priorityQueue.count;
  }

  //set a evaluatedNodes
  void setNumberOfStateEvaluated(int num) {
    this->_evaluatedNodes = num;
  }

  // return the number of node that evaluated
  int getNumberOfStateEvaluated() override {
    int temp = this->_evaluatedNodes;
    setNumberOfStateEvaluated(0);
    return temp;
  }

  virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;

  //get start and end and return the way
  vector<State<T>*> traceBack(State<T> *state) {
    vector<State<T>*> path;
    path.emplace_back(state);
    while (state->getCameFrom() != NULL) {
      state = state->getCameFrom();
      path.emplace_back(state);
    }
    return path;
}

  //check if the rhe set  contains input state
  bool isInClosedList(State<T> * state) {
    int i = -1;
    bool inClosed = false;
    for(State<T>* s: _setClose){
      i++;
      if(s->isEqual(state)){
        inClosed = true;
        break;
      }
    }
    return inClosed;
  }


  //check if the priority queue contains input state
  bool isOpenContains(State<T>* state) {
    vector<State<T>*> copy;
    bool isContain = false;
    while(!this->_priorityQueue.empty()) {
      copy.emplace_back(this->_priorityQueue.top());
      this->_priorityQueue.pop();
    }
    for (State<T>* s : copy) {
      this->_priorityQueue.push(s);
      if(s->isEqual(state)) {
        isContain = true;
      }
    }
    return isContain;
  }

  void addToCostSearch(double num) {
    this->_searchCost += num;
  }
};

#endif //EX4_SEARCH_ABSTRACTSEARCHER_H_

