//
// Created by shon on 11.1.2020.
//

#ifndef EX4_SERVER_SIDE_FILECACHEMANGER_H_
#define EX4_SERVER_SIDE_FILECACHEMANGER_H_

#include <list>
#include <unordered_map>

#include "CacheManager.h"

using namespace std;

/**
 * FileCacheManger class
 * creat a cash (map) to get last 10 used solution
 * and save in file the old solution
 */
class FileCacheManger: public CacheManager<string,string> {

  //typedef for Easy reading
  typedef typename std::pair<string, string> key_value_pair;
  typedef typename std::list<key_value_pair>::iterator list_iterator;

 private:
  unordered_map<string, string> _mapFileData;

  list<key_value_pair> _cache_items_list;
  unordered_map<string, list_iterator> _cache_items_map;
  int _limtSize;


 public:
  bool isExist(string problem) override;
  void  addToCache(string problem, string solution) override;
  void  deleteFromCache(string problem) override;
  string findSolution(string problem) override;

  FileCacheManger();

  // creating deep clone of the object
  CacheManager<string, string>* getClone() override {
    return new FileCacheManger();
  }


  ~FileCacheManger() override= default;

};

#endif //EX4_SERVER_SIDE_FILECACHEMANGER_H_
