//
// Created by shon on 11.1.2020.
//

#include <fstream>
#include <iostream>
#include "FileCacheManger.h"

// If problem not found in map return false
bool FileCacheManger::isExist(string problem) {
  if (!(_mapFileData.find(problem) == _mapFileData.end())) {
    return true;
  } else{
    std::ifstream infile(problem + ".txt");
    bool text = infile.good();
    return text;
  }

}
void FileCacheManger::addToCache(string problem, string solution) {
  //Searches the map for the value str and saves at 'it'
  auto it = _cache_items_map.find(problem);
  //Puts in the latest uses queue on the top
  _cache_items_list.push_front(key_value_pair(problem, solution));

  //Creating a txt - its name of the problem
  _mapFileData[problem];
  string name = problem + ".txt";
  ofstream fileOut;
  try {
    fileOut.open(name);
    if (!fileOut) {
      throw "Error opening file\n";
    }
    fileOut<<solution;
    cout<<"creat new file - "<<name<<endl;
    fileOut.close();
  } catch (int ex) {
    return;
  }

  //If it has already been in the recent list
  if (it != _cache_items_map.end()) {
    _cache_items_list.erase(it->second);
    _cache_items_map.erase(it);
  }
  //Enter to the map
  _cache_items_map[problem] = _cache_items_list.begin();
  //Checking if tje list is full
  if ((int)_cache_items_map.size() > _limtSize) {
    auto last = _cache_items_list.end();
    last--;
    _cache_items_map.erase(last->first);
    _cache_items_list.pop_back();
  }
}



void FileCacheManger::deleteFromCache(string problem) {
  if (isExist(problem)) {
    string name = problem + ".txt";
    if (remove((name).c_str()) != 0)
      perror("Error deleting file");
    else {
      puts("File successfully deleted");
    }
    _mapFileData.erase(problem);
  } else {
    cout << "this problem not in the cache, cant delete it\n";
  }
}

string FileCacheManger::findSolution(string problem) {
  string name = problem + ".txt";
  auto it = _cache_items_map.find(problem);
  //checking  if the key in the map
  if (it == _cache_items_map.end()) {
    try {
      ifstream infile(name);
      if (infile.good()) {
        string solution;
        string line;
        while (getline(infile, line)) {
          solution = solution + line;
        }
        _cache_items_list.push_front(make_pair(problem,solution));
        auto first = _cache_items_list.begin();
        infile.close();
        return solution;
      } else {
        throw "Error opening file\n";
      }
    } catch (int ex) {
      return problem;
    }

  } else {
    //Found on the map so we return the object through cache.
    _cache_items_list.splice(_cache_items_list.begin(), _cache_items_list, it->second);
    //cout<<"from cahche:\t";
    return it->second->second;
  }
}

FileCacheManger::FileCacheManger() {
  this->_limtSize = LIME_SIZE_CACHE;
}

