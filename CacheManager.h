//
// Created by shon on 11.1.2020.
//

#ifndef EX4_SERVER_SIDE_CACHEMANAGER_H_
#define EX4_SERVER_SIDE_CACHEMANAGER_H_

#define LIME_SIZE_CACHE 10;
#include "string"
using namespace std;

/**
 * CacheManager class.
 * manager how to save data of the program
 */
template<class key, class value>
class CacheManager {
 public:
  virtual bool isExist(key problem)=0;
  virtual void  addToCache(key problem, value solution)=0;
  virtual void  deleteFromCache(key problem)=0;
  virtual value findSolution(key problem)=0;
  virtual CacheManager* getClone()=0;

  virtual ~CacheManager() = default;
};

#endif //EX4_SERVER_SIDE_CACHEMANAGER_H_
