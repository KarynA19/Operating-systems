#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if (argc!=2) {
       printf("Error number paremetres\n");
        exit(1);
    }
    char buffer[1024];
    char* string = argv[1];
    string[strlen(string)-1] = '\0';//Removes the line break from the input
    int file_String = open(string,O_RDONLY, 0 ); //open new file 
    if (file_String<0){ //check if suceeded opening file
        printf("Error open file\n");
        exit(1);
    }
    int fd1 = read(file_String,buffer ,1024);//read the file
    if (fd1<0){//check if suceeded reading file
        printf("Error read file\n");
        exit(1);
    }
    buffer[strlen(buffer)] ='\0';
    printf("%s",buffer);
    close(file_String);//close the file
    return 0;
}