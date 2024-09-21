/*
============================================================================
Name : 33client.c
Author : Gnanendhar Reddy
Description : 33. Write a program to communicate between two machines using socket.
Date: 21st Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char message[1024];
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    if (send(client_socket, "Hello, This is Client!\n", 23, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(client_socket, message, sizeof(message), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Received message from server: %s\n", message);
    close(client_socket);
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/32$ cc 33client.c -o client
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/SoftwareSystems/List2/32$ ./client
Received message from server: Hello, This is Server!
*/
