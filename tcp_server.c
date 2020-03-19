#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){

// OUTLINE
    // socket() => bind() => listen() => accept()    

    char server_message[256] = "The message from Server !!!" ; 
    
    // creating a socket 
    int server_socket ; 
    server_socket = socket(AF_INET , SOCK_STREAM , 0);

    // Def. server address 
    struct sockaddr_in server_address ; 
    server_address.sin_family = AF_INET ; 
    server_address.sin_port = htons(9002) ; 
    server_address.sin_addr.s_addr = INADDR_ANY ; 

    // bind our socke to specific ip and port 
    int bind_ststus =  bind(server_socket , (struct sockaddr* ) &server_address , sizeof(server_address)) ; 

    // listen function 

    listen(server_socket , 5) ; 

    int client_socket ; 
    client_socket = accept(server_socket,NULL,NULL) ; 

    //sending data to client 
    send(client_socket, server_message , sizeof(server_message) , 0 );

    close(server_socket); 



}