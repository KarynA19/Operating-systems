#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
    if (argc!=3) {
       printf("Error number paremetres\n");
        exit(1);
    }
    double num1 = atof (argv[1]); //Turn the string into a number
    double num2 = atof (argv[2]); //Turn the string into a number
    double result = pow(num1,num2); //calculate 
    printf("%.1f\n",result);
    return result;

}