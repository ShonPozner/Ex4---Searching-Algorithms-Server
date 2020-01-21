//
// Created by shon on 17.1.2020.
//

#ifndef EX4_MISCELLANEOUS_STATECOMPARE_H_
#define EX4_MISCELLANEOUS_STATECOMPARE_H_

#include "State.h"

template <class T>
class StateCompare {
 public:
  // Returns whether left > right
  int operator() (State<T>* left, State<T>* right) {
    return left->getCost() > right->getCost();
  }

};

#endif //EX4_MISCELLANEOUS_STATECOMPARE_H_
