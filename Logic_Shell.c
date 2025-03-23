#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    char input[100];
    char *space = " ";
    char *token;
    char* arr[3];
    int i,j=1;
    char numberedInput[150];// buffer size to numbering
    int rc = open("Commands/Logic/Logic_Commands.txt", O_RDWR , 0777); // Open history file to write commands
    if (rc < 0) { // Check if succeeded opening file
        printf("Failed to open history file\n");
        exit(1);
    }

    while (1) {
        printf("LogicShell> "); // Print shell prompt
        if (fgets(input, 100, stdin) == NULL) { // Read user input
            printf("Failed to get input\n");
            break;
        }
        if (rc != -1) {
            int bytes_read;
            while ((bytes_read = read(rc, numberedInput, sizeof(numberedInput) - 1)) > 0) {
                numberedInput[bytes_read] = '\0';  
                for (int i = 0; i < bytes_read; i++) {
                    if (numberedInput[i] == '\n') {
                        j++;
                    }
                }
            }
        }
        lseek(rc, 0, SEEK_END);
        snprintf(numberedInput, sizeof(numberedInput), "%d. %s", j, input); // Format with number
        int rc2 = write(rc, numberedInput, strlen(numberedInput)); // Write to history file
        if (rc2 != strlen(numberedInput)) {
            printf("Error writing to file\n");
            exit(1);
        }
        j++; // Increment the history counter
    
        

        if (strcmp(input, "Cls\n") == 0) { // If user inputs "Cls", exit the shell
            exit(0);
        }

        if (strcmp(input, "History\n") == 0) { // If user inputs "History", execute history command
            int son = fork(); // Fork a child process
            if (son < 0) {
                printf("Error creating child process\n");
                exit(1);
            }
            if (son == 0) { // Child process executes the History program
                execl("./History", "History","Commands/Logic/Logic_Commands.txt", NULL);
                printf("Failed to execute History\n"); // Print error if execl fails
                exit(1);
            }
            wait(NULL); // Parent process waits for child to finish
            continue; // Continue to prompt
        }

        token = strtok(input, space); // Tokenize user input by space
        if (token != NULL) {
            if (strcmp(token, "Highbit") == 0) { // If user inputs "Highbit", execute Highbit program
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 1) {
                    arr[i] = token; // Store arguments after "Highbit"
                    i++;
                }
                if (i == 1) {
                    int son = fork(); // Fork a child process
                    if (son < 0) {
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) { // Child process executes the Highbit program
                        execl("./Highbit", "Highbit", arr[0], NULL);
                        printf("Failed to execute Highbit\n"); // Print error if execl fails
                        exit(1);
                    }
                    wait(NULL); // Parent process waits for child to finish
                    continue; // Continue to prompt
                }
            } else if (strcmp(token, "DectoBin") == 0) { // If user inputs "DectoBin", execute DectoBin program
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 1) {
                    arr[i] = token; // Store arguments after "DectoBin"
                    i++;
                }
                if (i == 1) {
                    int son = fork(); // Fork a child process
                    if (son < 0) {
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) { // Child process executes the DectoBin program
                        execl("./DectoBin", "DectoBin", arr[0], NULL);
                        printf("Failed to execute DectoBin\n"); // Print error if execl fails
                        exit(1);
                    }
                    wait(NULL); // Parent process waits for child to finish
                    continue; // Continue to prompt
                }
            } else if (strcmp(token, "DectoHex") == 0) { // If user inputs "DectoHex", execute DectoHex program
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 1) {
                    arr[i] = token; // Store arguments after "DectoHex"
                    i++;
                }
                if (i == 1) {
                    int son = fork(); // Fork a child process
                    if (son < 0) {
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) { // Child process executes the DectoHex program
                        execl("./DectoHex", "DectoHex", arr[0], NULL);
                        printf("Failed to execute DectoHex\n"); // Print error if execl fails
                        exit(1);
                    }
                    wait(NULL); // Parent process waits for child to finish
                    continue; // Continue to prompt
                }
            }
        }
        printf("Not Supported\n"); // If user input doesn't match any supported commands
    }
    close(rc); // Close history file
    return 0;
}
