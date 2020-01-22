//
// Created by shon on 11.1.2020.
//

#ifndef EX4_SERVER_SIDE_SERVER_H_
#define EX4_SERVER_SIDE_SERVER_H_

#include "ClientHandler.h"
namespace server_side {
    /**
    * Server interface
    */

  class Server {
   protected:
    bool _stopFlag;

  public:
    virtual void open(int port,ClientHandler *clientHandler) = 0;
    virtual void stop() = 0;


    virtual ~Server() = default;

    Server(){
      _stopFlag = false;
    }
  };
}


#endif //EX4_SERVER_SIDE_SERVER_H_
