#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc!=4) {
       printf("Error number paremetres\n");
        exit(1);
    }
    
    char *str=argv[1]; //sentence
    char *word=argv[2]; //word to replace
    int place=atoi(argv[3])-1; //place of index to replace word
    int wordlen=strlen(word); //save word length

    if (place < 0 || place >= strlen(str)) {
        printf("Error: Invalid index\n");
        exit(1);
    }

    for (int i = 0; i < wordlen; i++) //replace word in sentence
    {
        str[place+i]=word[i];
    }
    printf("%s\n",str);
    return 0;
     
}
