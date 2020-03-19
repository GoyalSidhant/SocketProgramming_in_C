#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


int main(){

//OUTLINE 
    // socket() => connection() => recv()

    int network_socket ; 
    // creating a socket 

    network_socket = socket(AF_INET , SOCK_STREAM , 0);

    // specifing the address to connect to  socket 
    struct sockaddr_in server_address ; 
    server_address.sin_family = AF_INET ; 
    server_address.sin_port = htons(9002) ; 
    server_address.sin_addr.s_addr = INADDR_ANY ; 

    int connection_status =  connect(network_socket , (struct sockaddr* ) &server_address , sizeof(server_address)) ; 


    // checking for errors 
    if(connection_status == -1){
        printf("Something wrong with the connections \n \n");
    }

    //recive data from server 
    char response[256] ; 
    recv(network_socket , &response ,  sizeof(response) , 0  ) ;

    // print out the data we get back 
    printf("THe data we got back: %s\n  ", response);

    //close the socket 
    close(network_socket);

    return 0 ;
}