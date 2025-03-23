#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(){


    if (access("Commands/Math", F_OK) == 0){
        if (unlink("Commands/Math/Math_Commands.txt") == -1) { //erase Math  text file    
            printf("Failed to remove Math_Commands.txt\n");
        }
        else if (rmdir("Commands/Math") == -1) { //remove math file 
            printf("Failed to remove Math file");
        }
    }
    if (access("Commands/Logic", F_OK) == 0){
        if (unlink("Commands/Logic/Logic_Commands.txt") == -1) { //erase Logic text file    
            printf("Failed to remove Logic_Commands.txt\n");
        }
        else if (rmdir("Commands/Logic") == -1) { //remove Logic file 
            printf("Failed to remove Logic file");
        }
    }
    if (access("Commands/String", F_OK) == 0){
        if (unlink("Commands/String/String_Commands.txt") == -1) { //erase String text file    
            printf("Failed to remove String_Commands.txt\n");
        }
        else if (rmdir("Commands/String") == -1) { //remove String file 
            printf("Failed to remove String file");
        }
    }
    if (rmdir("Commands") == -1) { //remove commands file  
            printf("Failed to remove commands file\n");
            exit(1);
    }
    printf("GoodBye\n");
    return 0;

}