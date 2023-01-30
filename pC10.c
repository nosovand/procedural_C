#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char currentLetter;
char temp[1000];
int wordLenght = 0;
char paredOne[1000] [1000];
char paredTwo[1000] [1000];
char unpaired[1000] [1000];
int parOneCount = 0;
int parTwoCount = 0;
int unpCount = 0;
int status = 1;
int space = 0;
int tmpLen = 0;

int main(){
    while (scanf("%c", &currentLetter)>0) {
        if(currentLetter == '<'){
            while ((scanf("%c", &currentLetter)>0) && (currentLetter != '>')){
                if(currentLetter == ' '){
                    space = wordLenght;
                }
                temp[wordLenght] = currentLetter;
                wordLenght++;
            }
            temp[wordLenght] = '\0';
                   if(space != 0){
                       temp[space] = '\0';
                       space = 0;
                   }
            if (temp[0] == '/'){
                memmove(temp, temp+1, strlen(temp));
                strcpy(paredTwo[parTwoCount], temp);
                parTwoCount++;
                //printf("test - %s, %s\n", temp, paredOne[parOneCount-1]);
                if(strcmp(temp, paredOne[parOneCount-1]) != 0){
                    printf("text nevalidni\n");
                    return 100;
                }
                else{
                    for(int k = parOneCount; k > 1; k--){
                        
                        tmpLen = strlen(paredOne[k-2]);
                        memmove(paredOne[k-1], paredOne[k-2], tmpLen);
                        paredOne[k-1][tmpLen] = '\0';
                        
                    }
                
                }
            
            }
            else if(temp[wordLenght-1] == '/'){
                strcpy(unpaired[unpCount], temp);
                unpCount++;
            }
            else {
                strcpy(paredOne[parOneCount], temp);
                parOneCount++;
            }
            wordLenght = 0;
}
}

    /*if(parOneCount != parTwoCount){
        printf("text nevalidni\n");
        return 100;
    }
     */
    int suma = parOneCount + unpCount;
    printf("pocet tagu: %d\n", suma);
    printf("text validni\n");
return 0;
}
