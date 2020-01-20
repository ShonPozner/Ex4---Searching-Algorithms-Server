//
// Created by shon on 16.1.2020.
//

#ifndef EX4_SLOVER_STRINGREVERSER_H_
#define EX4_SLOVER_STRINGREVERSER_H_


#include <iostream>
#include <string>
#include "Solver.h"
using namespace std;
/**
 * Solver interface
 */
class StringReverser: public Solver<string,string> {
  string solve(string problem) override;
  ~StringReverser() override = default;
  Solver<string, string>* getClone() override;


};

#endif //EX4_SLOVER_STRINGREVERSER_H_
