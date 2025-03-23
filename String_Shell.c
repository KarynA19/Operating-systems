#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    char input[100],temp1[100];
    char *space = " ";
    char *token;
    char* arr[3], temp[50];
    int i,j=1;
    char numberedInput[150]; // buffer size to numbering
    int rc = open("Commands/String/String_Commands.txt", O_RDWR | O_CREAT, 0777); // Open history file to write commands
    if (rc < 0) { // Check if succeeded opening file
        printf("Failed to open history file\n");
        exit(1);
    }

    while (1) {
        printf("StringShell> "); // Print shell prompt
        if (fgets(input, 100, stdin) == NULL) { // Read user input
            printf("Failed to get input\n");
            break;
        }

        strcpy(temp1, input); // Copy input to temp1 for future use
        // Write user input to history file
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
                execl("./History", "History","Commands/String/String_Commands.txt", NULL);
                printf("Failed to execute History\n"); // Print error if execl fails
                exit(1);
            }
            wait(NULL); // Parent process waits for child to finish
            continue; // Continue to prompt
        }

        token = strtok(input, space); // Tokenize user input by space
        if (token != NULL) {
            if (strcmp(token, "PrintFile") == 0) { // If user inputs "PrintFile", execute PrintFile program
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 1) {
                    arr[i] = token; // Store arguments after "PrintFile"
                    i++;
                }
                if (i == 1) {
                    int son = fork(); // Fork a child process
                    if (son < 0) {
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) { // Child process executes the PrintFile program
                        execl("./PrintFile", "PrintFile", arr[0], NULL);
                        printf("Failed to execute PrintFile\n"); // Print error if execl fails
                        exit(1);
                    }
                    wait(NULL); // Parent process waits for child to finish
                    continue; // Continue to prompt
                }
            } else if (strcmp(token, "Find") == 0) { // If user inputs "Find", execute Find program
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 2) {
                    arr[i] = token; // Store arguments after "PrintFile"
                    i++;
                }
                if (i == 2) {
                    int son = fork(); // Fork a child process
                    if (son < 0) {
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) { // Child process executes the Find program
                        execl("./Find", "Find", arr[0], arr[1], NULL);
                        printf("Failed to execute Find\n"); // Print error if execl fails
                        exit(1);
                    }
                    wait(NULL); // Parent process waits for child to finish
                    continue; // Continue to prompt
                }
            } else if (strcmp(token, "Replace") == 0) {// If user inputs "Replace", execute Replace program
                char sentence[100], word[50], index[10]; //for sentence to be changed
                sscanf(temp1, "%*s \"%[^\"]\" %s %s",sentence,word,index);
                int son = fork(); // Fork a child process
                if (son < 0) {
                printf("Error creating child process\n");
                exit(1);
                }
                if (son == 0) { // Child process executes the Replace program
                execl("./Replace", "Replace", sentence, word, index, NULL);
                printf("Failed to execute Replace\n"); // Print error if execl fails
                exit(1);
                }
                wait(NULL); // Parent process waits for child to finish
                continue; // Continue to prompt
                }
            
        
            printf("Not Supported\n"); // If user input doesn't match any supported commands
        }
    }
    close(rc); // Close history file
    return 0;
}
