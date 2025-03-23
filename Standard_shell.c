#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(){
    char input[100];
    
    int check = mkdir("Commands", 0777); // create new folder
    if (check == -1)
    {
        printf("error open folder\n");
        exit(1);
    }
    while(1){
        printf("StandShell> ");
        if((fgets(input, 100, stdin) != NULL)){ //check the input from user
            if(strcmp(input,"exit\n")==0){ //if asked to exit
                int son = fork();
                if (son<0){ //son didnt succeed
                    printf("Error son");
                    exit(1);
                }
                else if(son==0){  //son succeeded go exit the file math 
                    execl("./exit", "exit", NULL);
                }
                else{

                wait(NULL); //wait for son
                exit(1);

                }
            }
            else if(strcmp(input,"Math\n")==0){ //if asked for math
                int son = fork();
                if (son<0){ //son didnt succeed
                    printf("Error son");
                    exit(1);
                }
                else if(son==0){  //son succeeded go exit the file math 
                    execl("./Math", "Math", NULL);
                }
                else{
                    wait(NULL); //wait for son
                }
            }
            else if(strcmp(input,"Logic\n")==0){ //if asked for logic
                int son = fork();
                if (son<0){ //son didnt succeed
                    printf("Error son");
                    exit(1);
                }
                else if(son==0){ //fork succeded go execute logic
                    execl("./Logic", "Logic", NULL);
                }
                else{
                    wait(NULL); //wait for son
                }
            }
            else if (strcmp(input, "String\n") == 0) //if asked for String
            {
                int son = fork();
                if (son < 0) //son didnt succeed
                {
                    printf("Error son");
                    exit(1);
                }
                else if (son == 0) //fork succeded go execute String
                {
                    execl("./String", "./String", NULL);
                    
                }
                else
                {
                    wait(NULL); //wait for son
                }
            }
            else  //if not any file then asked for linux function
            {
                int son = fork();
                if (son < 0)  //son didnt succeed
                {
                    printf("Error son");
                    exit(1);
                }
                else if (son == 0) //fork succeded go execute function 
                {
                    input[strcspn(input, "\n")] = 0;
                    execlp(input, input, NULL);
                    printf("Not Supported\n"); //print not supported if son didnt succeed opening file
                    exit(1);
                }
                else{
                    wait(NULL); 
                }
                
            }
        
        }
    }
    return 0;
}