//
// Created by shon on 19.1.2020.
//

#ifndef EX4_SLOVER_SEARCHERADAPTER_H_
#define EX4_SLOVER_SEARCHERADAPTER_H_

#include "Solver.h"
#include "State.h"
#include "Searcher.h"

/**
 * SearcherAdapter class
 * creat a conction between solver and searcher
 */
template <class T>
class SearcherAdapter: public Solver<Searchable<T>*,vector<State<T>*>>  {
 private:
  Searcher<T>* _searcher;

 public:
  SearcherAdapter(Searcher<T> *searcher) {
    _searcher = searcher;
  }

  ~SearcherAdapter() {
    delete  _searcher;
  }

  vector<State<T>*> solve(Searchable<T>* searchable) {
    return _searcher->search(searchable);
  }

  //creating deep clone of the SearcherAdapter
  Solver<Searchable<T>*, vector<State<T>*>>* getClone() {
    return new SearcherAdapter<T> (this->_searcher->getClone());
  }


};

#endif //EX4_SLOVER_SEARCHERADAPTER_H_
