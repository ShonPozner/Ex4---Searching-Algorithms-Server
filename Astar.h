//
// Created by shon on 21.1.2020.
//

#ifndef EX4_SEARCH_ALGORITHMS_ASTAR_H_
#define EX4_SEARCH_ALGORITHMS_ASTAR_H_

#include <cfloat>
#include <unordered_map>
#include "AbstractSearcher.h"
#include <cmath>


using namespace std;


/**
 * Extra class
 * This class Extra save more information on the state
 */

template <class T>
class Extra {
  State<T>* _state;
  double _dis;
 public:
  Extra(State<T>* state) {
    this->_state = state;
    this->_dis = DBL_MAX;
  }
  // get the distance
  double getDistance() {
    return this->_dis;
  }
  // set the distance
  void setDistance(double dis) {
    this->_dis = dis;
  }
};



/**
 * A star class.
 * sort a A star white a set and priority Queue
 * every time go to the low cost node untel the goal
 */
template <class T>
class Astar: public AbstractSearcher<T> {

 private:
  // this map is used for mapping for a state object to the the object wraps it
  unordered_map<State<T>*, Extra<T>*> _stateToEx;


  double GetHeur(State<T>* state1, State<T>* state2) {
    int x1 = state1->getState()->getRow();
    int y1 = state1->getState()->getClo();
    int x2 = state2->getState()->getRow();
    int y2 = state2->getState()->getClo();
    return  sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  }

 public:
  vector<State<T>*> search(Searchable<T>* searchable);

  Astar():AbstractSearcher<T>() {};
  ~Astar() = default;

  // Creat a deep clone of the object
  Searcher<T>* getClone() {
    return new Astar<T>();
  }
};

template<class T>
vector<State<T> *> Astar<T>::search(Searchable<T> *searchable) {
  this->_setClose.clear();
  while (!this->_priorityQueue .empty()) {
    this->_priorityQueue.pop();
  }
  this->_stateToEx.clear();
  double wayCost =0;
  //push to the priorityQueue the initial state
  State<T>* n = searchable->getInitialState();
  this->_priorityQueue.push(n);
  State<T>* end = searchable->getGoalState();
  // making a new Extra for starting point and add to hash map
  Extra<T>* extra = new Extra<T>(n);
  this->_stateToEx[n] = extra;
  extra->setDistance(n->getState()->getCost());
  n->getState()->setCost(this->GetHeur(n,end) + n->getCost());

  while(!this->_priorityQueue.empty()) {
    n = this->popPriorityQueue();
    this->_setClose.insert(n);
    // Checking if n is a Goal state if return the back Trace
    if (searchable->isGoalState(n)) {
      return this->traceBack(n);
    }
    // get all the successors
    vector<State<T>*> successors;
    successors =searchable->getAllPossibleStates(n);

    for (State<T>* each : successors) {
      if(this->isInClosedList(each)) {
        continue;
      }
      // making a new Extra if this first time of this state
      if (this->_stateToEx.find(each)== this->_stateToEx.end()) {
        extra = new Extra<T>(each);
        this->_stateToEx[each] = extra;
      }
      wayCost = this->_stateToEx[n]->getDistance() + each->getState()->getCost();

      if(this->_stateToEx[each]->getDistance() > wayCost) {
        each->setCameFrom(n);
        this->_stateToEx[each]->setDistance(wayCost);
        each->getState()->setCost(this->GetHeur(each,end) + this->_stateToEx[each]->getDistance());
        each->setCost(n->getCost() + each->getCost());
        if(!this->isOpenContains(each)) {
          this->_priorityQueue.push(each);
        }
      }
    }
  }
  cerr << "error: cannot get the goal state" << endl;
  exit(1);

}

#endif //EX4_SEARCH_ALGORITHMS_ASTAR_H_
