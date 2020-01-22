//
// Created by shon on 20.1.2020.
//

#ifndef EX4_SERVER_MYPARALLELSERVER_H_
#define EX4_SERVER_MYPARALLELSERVER_H_

#include <vector>
#include <thread>
#include "Server.h"
using namespace server_side;
/**
 * MyParallelServer class
 * Handles multiple clients at the same time
 */
class MyParallelServer: public Server {
 private:
  vector<thread> _threadsVec;
  vector<bool>  _threadFlags;

 public:
  MyParallelServer();
  void open(int port, ClientHandler* c) override;
  void stop() override ;
  void startThread(int clientSocket, ClientHandler* c, int threadIndex);
  void joinTreads();

};

#endif //EX4_SERVER_MYPARALLELSERVER_H_
