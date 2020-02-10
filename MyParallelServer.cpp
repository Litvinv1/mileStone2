//
// Created by yuvalshechter on 06/02/2020.
//

#include "MyParallelServer.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
//#include <zconf.h>
#include "ClientHandler.h"
#include "MyClientHandler.h"
#include "Server.h"
#include "AStar.h"
#include "OA.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>

MyParallelServer::MyParallelServer() {}

void MyParallelServer::open(int port, ClientHandler *ch) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr{}, client_addr{};
    //Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        cerr << "Error opening socket" << endl;
        cout << strerror(errno);
        exit(-1);
    }
    // Bind IP_address to socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Error binding to address" << endl;
        cout << strerror(errno) << endl;
        this->stop(sockfd);
        exit(-2);
    }
    // Listen for connections until a certain amount of time
    if (listen(sockfd, SOMAXCONN) == -1) {
        std::cerr<<"Error during listening command"<<std::endl;
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    //listen(sockfd, SOMAXCONN);
    struct sockaddr_in cli_addr;
    int clilen;
    clilen = sizeof(cli_addr);
    struct timeval tv;
    tv.tv_sec = 120;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    while (true) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        if (newsockfd < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                break;
            } else {
                cerr << "Error accepting connection" << endl;
                cout << strerror(errno);
                break;
            }
        }
        threadsVec.emplace_back(thread(OAFunction, ch, newsockfd));
    }
    //cout << "im out of the loop in MyParallelServer";
    this->stop(sockfd);
    if (newsockfd != -1) {
        this->stop(newsockfd);
    }
}

void MyParallelServer::stop(int socket) {
    close(socket);
}

void MyParallelServer::OAFunction(ClientHandler *ch, int socket) {
    OA* searcher = new OA();
    ch = new MyClientHandler(searcher);
    ch->handleClient(socket);
}