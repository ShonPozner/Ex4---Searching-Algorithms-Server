//
// Created by shon on 17.1.2020.
//

#ifndef EX4_MISCELLANEOUS_CELL_H_
#define EX4_MISCELLANEOUS_CELL_H_

class Cell {
 private:
  int _row;
  int _clo;
  int _cost;

 public:

  //Constructor pair
  Cell(int row, int clo, int cost) {
    _row = row;
    _clo = clo;
    _cost = cost;
  }

  //Constructor pair
  Cell(pair<int,int> pairCell, int cost) {
    _row = pairCell.first;
    _clo = pairCell.second;
    _cost = cost;
  }

  //over write ==
  bool operator==(Cell* cell){
    //&& _cost == cell->getCost())
    return (cell->_clo ==_clo && cell->_row == _row );
  }


  int getRow(){
    return _row;
  }

  int getClo() {
    return _clo;
  }

  int getCost() {
    return _cost;
  }

  bool isEqual(Cell *cell) {
    //&& _cost == cell->getCost())
    bool test =(_row == cell->getRow() && _clo == cell->_clo);
    return test;
  }

  void setCost(int cost) {
    _cost = cost;
  }



};

#endif //EX4_MISCELLANEOUS_CELL_H_
