#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc , char* argv[]) {
    if (argc!=2) {
       printf("Error number paremetres\n");
        exit(1);
    }
    int num = atoi(argv[1]);//Turn the string into a number
    printf("%X\n", num); //Prints the hexadecimal value of the number
    return num;
}