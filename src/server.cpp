#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <thread>

#include "server.h"
#include "global.h"
#include "logicToBloomFilter.h"
#include "log.h"


using namespace std;

void handleClient(int client_socket, BloomFilter &bloomFilter)
{
    std::ostringstream oss;
    char buffer[4096];
    
    while (true)
    {
        int bytes = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes < 0)
        {
            perror("error reading from socket");
            break;  
        }

        if (bytes == 0)
        {
            std::cout << "Client disconnected." << std::endl;
            appendToLog("Client disconnected.");
            break;  
        }

        std::string line(buffer, bytes);
        
        std::istringstream iss(line);
        int command;
        std::string url;
        
        bool result = false;
        
        if (iss >> command >> url)
        {   
            oss << "command is: " << command << " and url is: " << url;
            appendToLog(oss.str());
            oss.str("");
            result = getUrls(command, url, bloomFilter);
            oss << "the result for this url: " << url <<  " is: " << result;
            appendToLog(oss.str());
            oss.str("");
        }
        
        if (result) {
            std::string response = "true";
            send(client_socket, response.c_str(), response.size(), 0);
        } else {
            std::string response = "false";
            send(client_socket, response.c_str(), response.size(), 0);
        }
    }

    close(client_socket);
}


int runServer(BloomFilter &bloomFilter)
{
    std::ostringstream oss;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
        return -1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(portServer);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding to socket");
        close(sock);
        return -1;
    }

    if (listen(sock, 5) < 0) 
    {
        perror("error listening on socket");
        close(sock);
        return -1;
    }

    cout << "Server is listening on port " << portServer << "..." << endl;
    oss << "Server is listening on port " << portServer << "...";
    appendToLog(oss.str());
    oss.str("");

    while (true)
    {
        struct sockaddr_in client_addr;
        unsigned int client_len = sizeof(client_addr);
        
        int client_socket = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0)
        {
            perror("error accepting connection");
            continue; 
        }

        char *client_ip = inet_ntoa(client_addr.sin_addr);
        uint16_t client_port = ntohs(client_addr.sin_port); 
        std::cout << "New connection from " << client_ip << ":" << client_port << std::endl;
        oss << "New connection from " << client_ip << ":" << client_port;
        appendToLog(oss.str());
        oss.str("");


        std::thread clientThread(handleClient, client_socket, std::ref(bloomFilter)); 
        clientThread.detach();  
    }

    close(sock);
    return 0;
}
