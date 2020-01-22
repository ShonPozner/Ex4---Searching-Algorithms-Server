//
// Created by shon on 20.1.2020.
//

#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "MyParallelServer.h"

// call to server constructor
MyParallelServer::MyParallelServer(): Server(){
}

// open server to lisning for 10 clint parallel
void MyParallelServer::open(int port, ClientHandler *c) {
  int clientSocket;
  int serverSocket;
  struct sockaddr_in server;

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

  //limit 10 clint
  if (listen(serverSocket, 11) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&timeout,sizeof(timeout))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  int threadCoun = 0;
  while (!this->_stopFlag) {
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);
    puts("Waiting for incoming connections...");
    // accept a client
    clientSocket = accept(serverSocket, (struct sockaddr *)&client, &clilen);
    if (clientSocket < 0) {
      if (errno == EWOULDBLOCK) {
        // wait for closing all the opened sockets, and then close the main server socket
        this->joinTreads();
        this->stop();
      } else {
        cout << "timeout Err" << endl;
      }
      continue;
    }
    this->_threadFlags.emplace_back(true);
    cout << "Connection accepted, starting listener thread - " <<threadCoun + 1 <<"\n" <<endl;
    this->_threadsVec.emplace_back(thread(&MyParallelServer::startThread, this, clientSocket, c, threadCoun));
    threadCoun++;
  }
  cout<<"close!\n";
  shutdown(serverSocket, SHUT_WR);
  close(serverSocket);

}



//stop this clint and get the another one
void MyParallelServer::stop() {
  this->_stopFlag = true;
}


// Start handle this client (this thread) using deep clone
void MyParallelServer::startThread(int clientSocket, ClientHandler *clientHandler, int index) {
  //Creating a deep clone of this handel
  ClientHandler* clone = clientHandler->getClone();
  clone->handleClient(clientSocket);
  // start handle this client (this thread),when done making the flag 0 , and close the socket
  this->_threadFlags[index]= false;
  close(clientSocket);
}


// wait for all client connections to be finished
void MyParallelServer::joinTreads() {
  for (unsigned int i = 0; i < this->_threadFlags.size(); i++) {
    if (this->_threadFlags[i]) {
      this->_threadsVec[i].join();
    }
  }
}
