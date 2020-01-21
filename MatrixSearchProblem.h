//
// Created by shon on 17.1.2020.
//

#ifndef EX4_SEARCH_SEARCHABLE_MATRIXSEARCHPROBLEM_H_
#define EX4_SEARCH_SEARCHABLE_MATRIXSEARCHPROBLEM_H_

#include "Searchable.h"
#include "../../Miscellaneous/Cell.h"
using namespace std;


class MatrixSearchProblem: public Searchable<Cell*> {

  typedef typename std::pair<int,int> pair_Cell;


 private:
  vector<vector<int>> _matrix;

 public:

  explicit MatrixSearchProblem(vector<vector<int>>& matrix);

  bool isGoalState(State<Cell*>* state);
  State<Cell*>* getGoalState();
  State<Cell*>* getInitialState() override;
  vector<State<Cell*>*> getAllPossibleStates(State<Cell*>* state) override;
   string getString();

   ~MatrixSearchProblem() = default;

   void MatrixToStrig(vector<vector<int>>& matrix, string& str);

  Searchable<Cell*>* getClone();



};

#endif //EX4_SEARCH_SEARCHABLE_MATRIXSEARCHPROBLEM_H_
