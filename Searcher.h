//
// Created by shon on 16.1.2020.
//

#ifndef EX4_SEARCH_SEARCHER_H_
#define EX4_SEARCH_SEARCHER_H_

#endif //EX4_SEARCH_SEARCHER_H_
#include "Searchable/Searchable.h"
#include "../slover/Solver.h"
/**
 * Searcher interface
 */
template <class T>
class Searcher {
 protected:
  double _searchCost;
  int _evaluatedNodes;

  Searcher(double cost, int evaluateCost) {
    _searchCost = cost;
    _evaluatedNodes = evaluateCost;
  }

 public:
  // the search method
  virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;
  // creat a clone
  virtual Searcher<T>* getClone() = 0;


  // get how many state were evaluated by the algorithm
  virtual int getNumberOfStateEvaluated() = 0;
  virtual ~Searcher() = default;
};