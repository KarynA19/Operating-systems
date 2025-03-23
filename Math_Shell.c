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
    char numberedInput[150]; // buffer size to numbering
    int rc = open("Commands/Math/Math_Commands.txt", O_RDWR | O_CREAT, 0777); // open history file to write commands
    if (rc < 0) { // check if succeeded opening file
        printf("Failed to open history file\n");
        exit(1);
    }

    while (1) {
        printf("MathShell> ");
        if (fgets(input, 100, stdin) == NULL) {
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
        

        if (strcmp(input, "Cls\n") == 0) {
            exit(0); // Exit the program cleanly if user types "Cls"
        }

        if (strcmp(input, "History\n") == 0) {// Execute "History" command to display command history
            int son = fork();
            if (son < 0) {
                printf("Error creating child process\n");
                exit(1);
            }
            if (son == 0) {
                execl("./History", "History", "Commands/Math/Math_Commands.txt", NULL);
                printf("Failed to execute History\n"); // If execl fails
                exit(1);
            }
            wait(NULL);
            continue;
        }

        // Tokenize the input command to determine which operation to perform
        token = strtok(input, space);
        if (token != NULL) {
            if (strcmp(token, "Sqrt") == 0) {// Execute "Sqrt" command with one argument
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 1) {
                    arr[i] = token;
                    i++;
                }
                if (i == 1) {
                    int son = fork();
                    if (son < 0) {//if we are not in sun
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) {//if we are in sun
                        execl("./Sqrt", "Sqrt", arr[0], NULL);
                        printf("Failed to execute Sqrt\n"); // If execl fails
                        exit(1);
                    }
                    wait(NULL);
                    continue;
                }
            } else if (strcmp(token, "Power") == 0) {// Execute "Power" command with two arguments
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 2) {
                    arr[i] = token;
                    i++;
                }
                if (i == 2) {
                    int son = fork();
                    if (son < 0) {//if we are not in sun
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) {//if we are in sun
                        execl("./Power", "Power", arr[0], arr[1], NULL);
                        printf("Failed to execute Power\n"); // If execl fails
                        exit(1);
                    }
                    wait(NULL);
                    continue;
                }
            } else if (strcmp(token, "Solve") == 0) {// Execute "Solve" command with three arguments
                i = 0;
                while ((token = strtok(NULL, space)) != NULL && i < 3) {
                    arr[i] = token;
                    i++;
                }
                if (i == 3) {
                    int son = fork();
                    if (son < 0) { //if we are not in sun
                        printf("Error creating child process\n");
                        exit(1);
                    }
                    if (son == 0) {//if we are in sun
                        execl("./Solve", "Solve", arr[0], arr[1], arr[2], NULL);
                        printf("Failed to execute Solve\n"); // If execl fails
                        exit(1);
                    }
                    wait(NULL);
                    continue;
                }
            }
        }
        printf("Not Supported\n"); // Print if the command is supported
    }
    close(rc); // Close the history file
    return 0;
}

  