//
// Created by shon on 16.1.2020.
//

#include<bits/stdc++.h>

#include "StringReverser.h"

string StringReverser::solve(string problem) {
  string solution ;
  for(int i = problem.length() - 1; i >= 0; i--){
    solution += problem[i];
  }
  return solution;
}
Solver<string, string> *StringReverser::getClone() {
    return new StringReverser();
  }
