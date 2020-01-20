//
// Created by shon on 11.1.2020.
//


#ifndef EX4_SERVER_SIDE_CLIENTHANDLER_H_
#define EX4_SERVER_SIDE_CLIENTHANDLER_H_
#include <iostream>
using namespace std;
/**
 * ClientHandler interface...
 */
class ClientHandler {

 public:
  virtual void handleClient(int clientSocket) = 0;
  virtual ClientHandler* getClone() = 0;
  virtual ~ClientHandler() = default;
};

#endif //EX4_SERVER_SIDE_CLIENTHANDLER_H_
