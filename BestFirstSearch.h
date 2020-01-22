//
// Created by shon on 17.1.2020.
//

#ifndef EX4_SEARCH_ALGORITHMS_BESTFIRSTSEARCH_H_
#define EX4_SEARCH_ALGORITHMS_BESTFIRSTSEARCH_H_

<<<<<<< HEAD
#include "AbstractSearcher.h"
=======
#include "../AbstractSearcher.h"
>>>>>>> origin

/**
 * BestFirstSearch class.
 * sort a Best First Search white a set and priority Queue
 * every time go to the low cost node untel the goal
 */
template <class T>
class BestFirstSearch: public AbstractSearcher<T> {

 public:

  BestFirstSearch():AbstractSearcher<T>(){};
  ~BestFirstSearch() = default;

  vector<State<T>*> search(Searchable<T>* searchable);

  // Creat a deep clone of the object
  Searcher<T>* getClone() {
    return new BestFirstSearch<T>();
  }

};

//search vector of states thar is a way from initial state to goal state
template<class T>
vector<State<T> *> BestFirstSearch<T>::search(Searchable<T> *searchable) {
  this->_setClose.clear();
  while (!this->_priorityQueue .empty()) {
    this->_priorityQueue.pop();
  }
  //push to the priorityQueue the initial state
  this->_priorityQueue.push(searchable->getInitialState());
  while(!this->_priorityQueue.empty()) {
    State<T>* n = this->popPriorityQueue();
    this->_setClose.insert(n);
    // Checking if n is a Goal state if return the back Trace
    if (searchable->isGoalState(n)) {
      return this->traceBack(n);
    }
    vector<State<T>*> successors;
    successors =searchable->getAllPossibleStates(n);
    for (State<T>* each : successors) {
      //If s is not in CLOSED and s is not in OPEN:
      if ((!this->isInClosedList(each) && !this->isOpenContains(each))) {
        each->setCameFrom(n);
        each->setCost(n->getCost() + each->getCost());
        this->_priorityQueue.push(each);
      } else {
        //Otherwise, if this new path is better than previous one
        double sum = n->getCost() + each->getCost();
        if(each->getCost() > sum) {
          each->setCameFrom(n);
          each->setCost(sum);
          if(!(this->isOpenContains(each))) {
            this->_priorityQueue.push(each);
          }
        }
      }
    }
  }
  cerr << "error: cannot get the goal state" << endl;
  exit(1);
}

#endif //EX4_SEARCH_ALGORITHMS_BESTFIRSTSEARCH_H_
