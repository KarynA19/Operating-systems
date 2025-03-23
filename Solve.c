#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]){
    if (argc!=4) {
       printf("Error number paremetres\n");
        exit(1);
    }

    double a = atof (argv[1]);//Turn the string into a number
    double b = atof (argv[2]);//Turn the string into a number
    double c = atof (argv[3]);//Turn the string into a number
    double result_sum = (pow(b,2)-(4*a*c)); //Calculate the root
    double x1=0 , x2=0;
    if (result_sum<0){ // If the number under the root is less than 0, there is no real solution
        printf("No Sol!\n");
    }
    else{
        if(sqrt(result_sum)==0){ //If the number under the root is equal to 0 there is one answer
            x1= (-b/(2*a));
            printf("%1.f\n",x1);
        
        }
        else{ //there is two answers
            x1= ((-b+sqrt(result_sum))/(2*a));
            printf("%1.f\n",x1);
            x2= ((-b-sqrt(result_sum))/(2*a));
            printf("%1.f\n",x2);
      
        }
    }
    return 0;
    
}