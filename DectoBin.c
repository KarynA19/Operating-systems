#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc , char* argv[]) {
   if (argc!=2) {
       printf("Error number paremetres\n");
        exit(1);
    }
    int num = atoi(argv[1]);//Turn the string into a number
    int result = 0,i=0;
    while (num > 0) { //A loop that calculates the binary value of the number 
        result = num & 1;
        num >>= 1;
        printf("%d", result);
        i++; 
    }
    printf("\n");
    return result;
}



