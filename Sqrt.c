#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc!=2) {
       printf("Error number paremetres\n");
        exit(1);
    }
    double num = atof(argv[1]); //Turn the string into a number
    if (num<0){ //If the number is negative, a root cannot be calculated
        printf("Math Error!\n");
        exit(1);
    }
    double number = sqrt(num);//calculate 
    printf("%.1f\n",number);
    return number;

}
