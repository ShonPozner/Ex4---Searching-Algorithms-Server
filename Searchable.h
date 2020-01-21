//
// Created by shon on 16.1.2020.
//

#ifndef EX4_SEARCH_SEARCHABLE_H_
#define EX4_SEARCH_SEARCHABLE_H_
#include <string>
#include <vector>
#include "../../Miscellaneous/State.h"

using namespace std;

/**
 * Searchable interface
 */
template <class T>
class Searchable {
 protected:
  vector<State<T>*> _goalStates;
  State<T>* _start;
  string _name;

  Searchable(){
    _start = nullptr;
    _name = "";
  }

  void setGoalStates(State<T>* end) {
    _goalStates.push_back(end);
  }
  void setStart(State<T>* start) {
    _start = start;
  }

 public:
  virtual bool isGoalState(State<T>* state) = 0;
  virtual State<T>* getInitialState() = 0;
  virtual State<T>* getGoalState() = 0;
  virtual vector<State<T>*> getAllPossibleStates(State<T>* state) = 0;
  virtual string getString() = 0;
  virtual Searchable<T>* getClone() = 0;
  virtual ~Searchable() = default;

  void setName(string str) {
    hash<string> hasher;
    auto hashed = hasher(str);
    _name = to_string(hashed);
  }


};



#endif //EX4_SEARCH_SEARCHABLE_H_
