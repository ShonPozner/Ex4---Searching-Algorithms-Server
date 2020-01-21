//
// Created by shon on 17.1.2020.
//

#ifndef EX4_MISCELLANEOUS_STATE_H_
#define EX4_MISCELLANEOUS_STATE_H_

#include <iostream>
#include <string>
using namespace std;


template <class T>
class State {

 private:
  T _state;
  double _cost;
  State<T> *_cameForm;


 public:
  //CTOR
  explicit State<T>(T state){
    _state = state;
    _cost = 0;
    _cameForm = nullptr;
  }

  //checking if s is equal to this state
  bool isEqual(State<T>* s) {
    bool test =_state->isEqual(s->getState());
    return test;
  }

  double getCost();

  T getState();

  State<T>* getCameFrom();

  void setCost(double cost);

  void setCameFrom(State<T> *s);

};





template<class T>
double State<T>::getCost() {
  return this->_cost;
}

template<class T>
T State<T>::getState() {
  return this->_state;
}

template<class T>
State<T> *State<T>::getCameFrom() {
  return _cameForm;
}

template<class T>
void State<T>::setCost(double cost) {
  _cost = cost;
}

template<class T>
void State<T>::setCameFrom(State<T> *s) {
  _cameForm = s;
}

#endif //EX4_MISCELLANEOUS_STATE_H_
