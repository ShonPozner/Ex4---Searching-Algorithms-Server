//
// Created by shon on 18.1.2020.
//

#ifndef EX4_MISCELLANEOUS_CELLCOMPER_H_
#define EX4_MISCELLANEOUS_CELLCOMPER_H_

#include "State.h"

template <class T>
class CellComper {
   public:
    // Returns whether left > right
    bool operator() (State<T>* left, State<T>* right) {
      bool test = (!left->isEqual(right));
      return test;
    }
};

#endif //EX4_MISCELLANEOUS_CELLCOMPER_H_
