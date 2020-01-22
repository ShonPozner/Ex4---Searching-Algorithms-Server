//
// Created by shon on 17.1.2020.
//

#include "MatrixSearchProblem.h"

MatrixSearchProblem::MatrixSearchProblem(vector<vector<int>>& matrix):Searchable() {
  //Init name from hash code
  string str= "";
  MatrixToStrig(matrix, str);
  setName(str);


  int sizeMatrix = matrix.size();

  // Init the start find way
  pair<int,int> pairTemp = make_pair(matrix[sizeMatrix - 2][0], matrix[sizeMatrix - 2][1]);
  Cell *cellStart = new Cell(pairTemp,matrix[pairTemp.first][pairTemp.second]);
  State<Cell*> *stateStart = new State<Cell*>(cellStart);
  this->setStart(stateStart);
  this->_start->setCost(matrix[pairTemp.first][pairTemp.second]);

  //Init the goal state noted only one goal!!
  pairTemp = make_pair(matrix[sizeMatrix - 1][0],matrix[sizeMatrix - 1][1]);
  Cell *cellGoal = new Cell(pairTemp,matrix[pairTemp.first][pairTemp.second]);

  this->setGoalStates(new State<Cell*>(cellGoal));
  this->_goalStates[0]->setCost(matrix[pairTemp.first][pairTemp.second]);


  _matrix = matrix;

}

/**
 * return if state is goal state.
 * Noted checking only one goal state.
 * @param state
 * @return bool
 */
bool MatrixSearchProblem::isGoalState(State<Cell*> *state) {
  return (state->isEqual(this->_goalStates[0]));
}

//get goal state (only the first)
State<Cell*>* MatrixSearchProblem::getGoalState() {
  return this->_goalStates[0];
}
// get the start of the state
State<Cell*> *MatrixSearchProblem::getInitialState() {
  return this->_start;
}
// get the name of this matrix injective (one-to-one) name
string MatrixSearchProblem::getString() {
  return this->_name;
}

/* getAllPossibleStates:
 *  checking all the valid state neighbor
 *  if te state on the ege of the matrix take the valid
 *  checking if state = -1 and than return empty vector
 *  @return result vector of state
 */
vector<State<Cell*>*> MatrixSearchProblem::getAllPossibleStates(State<Cell*>* state) {
  vector<State<Cell*>*> result;
  State<Cell*>* temp;
  unsigned int row = state->getState()->getRow();
  unsigned int col = state->getState()->getClo();
  // we in state that equal to -1 than cant move on
  if (_matrix[row][col] == -1) {
    return result;
  }
  // checking if we in the first row
  if (row != 0 && _matrix[row-1][col] != -1) {
    temp = new State<Cell*>(new Cell(make_pair(row-1, col),_matrix[row-1][col]));
    temp->setCost(_matrix[row-1][col]);
    result.push_back(temp);
  }
  // checking if we in last row
  if (row+1 < _matrix.size()-2 && _matrix[row+1][col] != -1) {
    temp = new State<Cell*>(new Cell(make_pair(row+1, col),_matrix[row+1][col]));
    temp->setCost(_matrix[row+1][col]);
    result.push_back(temp);
  }

  // checking if we in the first col
  if (col != 0  && _matrix[row][col-1] != -1) {
    temp = new State<Cell*>(new Cell(make_pair(row, col-1),_matrix[row][col-1]));
    temp->setCost(_matrix[row][col-1]);
    result.push_back(temp);
  }

  // checking if we in the last col
  if (col+1 < _matrix[0].size() && _matrix[row][col+1] != -1) {
    temp = new State<Cell*>(new Cell(make_pair(row, col+1),_matrix[row][col+1]));
    temp->setCost(_matrix[row][col+1]);
    result.push_back(temp);
  }

  return result;
}
// creating deep clone of the object
Searchable<Cell*> * MatrixSearchProblem::getClone() {
  // Declaring new vector
  vector<vector<int>> copy;

  // Copying vector by copy function
  for(int i = (int)this->_matrix.size() - 1 ; i >= 0; i--) {
    copy.emplace_back(this->_matrix[i]);
  }
  return new MatrixSearchProblem(copy);
}


// creat string from matrix
void MatrixSearchProblem::MatrixToStrig(vector<vector<int>> &vec, string &str) {
  for (unsigned int i=0; i<vec.size(); i++) {
    str +="#";
    for (unsigned int j=0; j<vec[i].size() ;j++) {
      str += to_string((int)(vec[i][j] +0.5));
    }
  }
}

