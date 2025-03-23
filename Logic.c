#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
    DIR *dir = opendir("Commands/Logic");
    if (dir){
        execl("./Logic_Shell","Logic_Shell",NULL);//Go run another file
        printf("Error\n");
        return 0;
    }
    else{
           
        if (mkdir("Commands/Logic", 0777)==-1){//Checking if we were able to open the folder
        printf("error open folder\n");
        exit(1);
        
        }
        int file_Logic = open("Commands/Logic/Logic_Commands.txt", O_WRONLY|O_RDONLY| O_CREAT , 0777 ); //open new file 
        if (file_Logic<0){//Checking if we were able to open the file
        printf("Error open file\n");
        exit(1);
        
        }

        close(file_Logic);//close the file
        execl("./Logic_Shell","Logic_Shell",NULL);//Go run another file
        printf("Error\n");
        return 0;

    }

}