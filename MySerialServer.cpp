//
// Created by shon on 11.1.2020.
//

#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "MySerialServer.h"


// stop flag get false
MySerialServer::MySerialServer(): Server() {
}

// open server to lisning on other thread
void MySerialServer::open(int port, ClientHandler *clientHandler) {
  thread thread(&MySerialServer::start,this,port,clientHandler);
  thread.join();
}

void MySerialServer::start(int port, ClientHandler *clientHandler) {
  int clientSocket;
  int serverSocket;
  struct sockaddr_in server, client;

  struct timeval timeout{};
  timeout.tv_sec = 60;

  // Creating socket file descriptor
  if ((serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  // Forcefully attaching socket to the port 8080
  if (bind(serverSocket, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&timeout,sizeof(timeout))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  if (listen(serverSocket, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (!_stopFlag) {
    //Accept and incoming connection
    socklen_t clilen = sizeof(client);
    puts("Waiting for incoming connections...");
    clientSocket = accept(serverSocket, (struct sockaddr *)&client, &clilen);
    if (clientSocket < 0) {
      if (errno == EWOULDBLOCK) {
        cout << "timeout" << endl;
      } else {
        cout << "error with client socket" << endl;
      }
      this->stop();
      continue;
    }
    cout << "Connection accepted, starting listener thread" << endl;
    clientHandler->handleClient(clientSocket);
  }

  cout<<"close!\n";
  shutdown(serverSocket, SHUT_WR);
  close(serverSocket);
}

void MySerialServer::stop() {
  _stopFlag = true;
}
MySerialServer::~MySerialServer() {
}
