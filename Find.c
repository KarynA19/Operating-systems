#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc!=3) {
       printf("Error number paremetres\n");
        exit(1);
    }
    char buffer[1024];
    char* check;
    char* string = argv[1];
    int file_String = open(string,O_RDONLY, 0); //open new file 
    if (file_String<0){//check if suceeded opening file
        printf("Error open file\n");
        exit(1);
    }
    int fd1 = read(file_String,buffer ,1024);//read the file
    if (fd1<0){//check if suceeded reading file
        printf("Error read file\n");
        exit(1);
    }
    argv[2][strlen(argv[2])-1] = '\0'; 
    check = strstr(buffer, argv[2]); //Checks if the word we received exists in the file
    if (check==NULL){
        printf("Try Again\n");
    }
    else{
        printf("Win\n");
    }
    close(file_String);//close the file
    return 0;
}