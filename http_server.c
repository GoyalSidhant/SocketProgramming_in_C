#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h> 


int main(){
    FILE* html_data ; 
    html_data =  fopen("index.html", "r") ; 

    char response_data[1024] ; 
    fgets(response_data , sizeof(response_data) , html_data) ; 
    

    return 0 ; 

}