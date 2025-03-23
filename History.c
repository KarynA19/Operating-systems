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
    char buff[1024];
    int rc1 = open(argv[1] ,O_RDONLY , 0);//open the file
    if (rc1 <0) { //check if suceeded opening file
        printf("Failed to open history file\n");
        exit(1);
    }
    int rc2 = read(rc1 ,buff ,1024);//read the file
    if (rc2<0) { //check if suceeded reading file
        printf("Failed to open history file\n");
        exit(1);
    }
    printf("%s",buff);
    close(rc1);//close the file
    return 0;
}