//
// Created by shon on 11.1.2020.
//

#ifndef EX4_SERVER_SIDE_SOLVER_H_
#define EX4_SERVER_SIDE_SOLVER_H_

template <class Problem, class Solution>
class Solver {

 public:

  virtual Solution solve(Problem) =0;
  virtual Solver* getClone() =0;
  virtual ~Solver() = default;
};

#endif //EX4_SERVER_SIDE_SOLVER_H_
