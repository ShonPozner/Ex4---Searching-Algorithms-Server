//
// Created by shon on 19.1.2020.
//

#ifndef EX4_MISCELLANEOUS_UTILS_H_
#define EX4_MISCELLANEOUS_UTILS_H_

#include <string>
#include <vector>
using namespace std;


class Utils {

 public:

  static vector<string> splitStr(string str, const string &delim){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
      pos = str.find(delim, prev);
      if (pos == string::npos) pos = str.length();
      string token = str.substr(prev, pos-prev);
      if (!token.empty()) tokens.push_back(token);
      prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
      return tokens;
  }

  static string removeSpaces(const string &str) {
    string result;
    for (char c : str) {
      if (c != ' ') {
        string temp(1, c);
        result += temp;
      }
    }
    return result;
  }

  static string buildSolution(vector<State<Cell*>*> vecSolution) {
    string str = "";
    for (int i = (int)vecSolution.size() - 1; i>0 ; i--) {
      int x = vecSolution[i]->getState()->getRow();
      int y = vecSolution[i]->getState()->getClo();
      int x2 = vecSolution[i - 1]->getState()->getRow();
      int y2 = vecSolution[i - 1]->getState()->getClo();
      double cost = vecSolution[i - 1]->getCost();
      if (x > x2) {
        str += "Up ";
      }
      if (x < x2) {
        str += "Down ";
      }
      if (y < y2) {
        str += "Right ";
      }
      if (y > y2) {
        str += "Left ";
      }
      str += "(" + to_string((int) cost) + ")";
      if (i != 1) {
        str += " ,";
      }
    }
    return str;
  }

};




#endif //EX4_MISCELLANEOUS_UTILS_H_
