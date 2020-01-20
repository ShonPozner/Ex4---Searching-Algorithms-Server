//
// Created by shon on 11.1.2020.
//

#ifndef EX4_SERVER_SIDE_MYTESTCLIENTHANDLER_H_
#define EX4_SERVER_SIDE_MYTESTCLIENTHANDLER_H_

#include "../slover/Solver.h"
#include "ClientHandler.h"
#include "../cahche/CacheManager.h"
#include <vector>

#define MAXPACKETSIZE 2048
/**
 * MyTestClientHandler class
 *
 */
class MyTestClientHandler: public ClientHandler {
 private:
  Solver<string, string> *_solver;
  CacheManager<string, string> *_cacheManager;

 public:
  ClientHandler* getClone() override;

  MyTestClientHandler(CacheManager<string, string> *cacheMan, Solver<string, string> *solver);

  void handleClient(int clientSocket) override;

  string getSolution(string fixMsg);
  string fixLine(string msg);
};
#endif //EX4_SERVER_SIDE_MYTESTCLIENTHANDLER_H_
