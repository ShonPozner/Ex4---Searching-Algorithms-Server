//
// Created by shon on 18.1.2020.
//

#ifndef EX4_SEARCH_ALGORITHMS_BREADTHFIRSTSEARCH_H_
#define EX4_SEARCH_ALGORITHMS_BREADTHFIRSTSEARCH_H_
#include "AbstractSearcher.h"

/**
 * BreadthFirstSearch class.
 * sort a Breadth First Search white a set and priority Queue
 * new node that checking add one to the cost
 */
template <class T>
class BreadthFirstSearch: public AbstractSearcher<T> {

 public:

  BreadthFirstSearch():AbstractSearcher<T>(){};
  ~BreadthFirstSearch() = default;

  vector<State<T>*> search(Searchable<T>* searchable);

  Searcher<T>* getClone() {
    return new BreadthFirstSearch<T>();
  }

};
template<class T>
vector<State<T> *> BreadthFirstSearch<T>::search(Searchable<T> *searchable) {
  //push to the priorityQueue the initial state
  this->_priorityQueue.push(searchable->getInitialState());
  //Inserting s in queue until all its neighbour vertices are marked
  this->_setClose.insert(searchable->getInitialState());
  //while ( Q is not empty)
  while(!this->_priorityQueue.empty()) {
    //V pop of the queue (dequeue)
    State<T>* v = this->popPriorityQueue();
    // Checking if n is a Goal state if return the back Trace
    if (searchable->isGoalState(v)) {
      return this->traceBack(v);
    }

    //processing all the neighbours of v
    vector<State<T>*> successors;
    successors =searchable->getAllPossibleStates(v);

    //for all neighbours w of v in Graph
    for (State<T>* w : successors) {
      //if w is not visited
      if (!this->isInClosedList(w)) {
        //Q.enqueue( w )
        w->setCost(v->getCost()+1);
        w->setCameFrom(v);
        this->_priorityQueue.push(w);
        //mark w as visited.
        this->_setClose.insert(w);
      }
    }
  }
  cerr << "error: cannot get the goal state" << endl;
  exit(1);
}

#endif //EX4_SEARCH_ALGORITHMS_BREADTHFIRSTSEARCH_H_
