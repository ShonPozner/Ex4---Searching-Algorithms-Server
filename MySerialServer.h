//
// Created by shon on 11.1.2020.
//

#ifndef EX4_SERVER_SIDE_MYSERIALSERVER_H_
#define EX4_SERVER_SIDE_MYSERIALSERVER_H_
#include <thread>
#include "Server.h"

using namespace std;
using namespace server_side;

class MySerialServer: public Server{

 private:
  thread _thread;

 public:
  void open(int port,ClientHandler *clientHandler) override ;

  void stop() override;

  void start(int port, ClientHandler *clientHandler);

  MySerialServer();
  ~MySerialServer() override;

};

#endif //EX4_SERVER_SIDE_MYSERIALSERVER_H_
