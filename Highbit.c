#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc , char* argv[]) {
    if (argc!=2) {
       printf("Error number paremetres\n");
        exit(1);
    }
    int num = atoi(argv[1]); //Turn the string into a number
    int count = 0;
    while (num > 0) { //A loop that counts the number of bits whose value is 1
        count += num & 1;
        num >>= 1;
    }
    printf("%d\n",count);
    return count;
}



