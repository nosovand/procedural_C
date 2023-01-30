#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char currentLetter;
int numberOfStrings = 1;
int numberOfLetters = 1;
char** mainArray;
int i = 0;
int j = 0;
char tmp;
int* arrayOfRepeats;
int minWords[10000];
int maxWords[10000];
int maxCount = 1;
int minCount = 100000;
int mx = 0;
int mn = 0;
int caseSense = 0;
int set = -1;
int len = -1;
int wordCount = 0;


int main(int argc, char *argv[])
{
    for(int k = 0; k < argc; k++){
        if(strcmp(argv[k],"-c") == 0) {
            caseSense = 1;
        }
        if(strcmp(argv[k], "-s") == 0) {
            set = atoi(argv[k+1]);
            if ((set <= 0 || set > 2) && set != -1) {
                set = 0;
                fprintf(stderr, "Warning: Chybna hodnota parametru -s!\n");
                
            }
        }
        
        if(strcmp(argv[k], "-l") == 0){
            if (k+1 < argc && atoi(argv[k+1]) > -1){
                len = atoi(argv[k+1]);
            }
            else {
                fprintf(stderr, "Warning: Chybna hodnota parametru -l!\n");
                len = -1;
            }
        
        }
    }
    mainArray = (char**)malloc(numberOfStrings * sizeof(char*));
    mainArray[0] = (char*)malloc(numberOfLetters * sizeof(char)+sizeof(char));
    arrayOfRepeats = (int*)malloc(numberOfStrings * sizeof(int));
    arrayOfRepeats[0] = 1;
    while(scanf("%c", &tmp)>0){
        if(isalpha(tmp) || isdigit(tmp)){

            if(caseSense == 0 && isupper(tmp)){
                tmp = tmp + 32;
            }
            mainArray[i][j] = tmp;
            j++;
            numberOfLetters++;
            mainArray[i] = realloc(mainArray[i], numberOfLetters * sizeof(char)+sizeof(char));
        }
        else{
            if(j == 0){continue;}
            int compareResult = 0;
            
            mainArray[i][j] = '\0';
           
          
            
            for (int l = 0; l < i; l++){
                if(strcmp(mainArray[i], mainArray[l]) == 0){
                    arrayOfRepeats[l]++;
                    j = 0;
                    numberOfLetters = 1;
                    compareResult = 1;
                }
                if (arrayOfRepeats[l] >= maxCount){
                    maxCount = arrayOfRepeats[l];
                }
                if (arrayOfRepeats[l] <= minCount){
                    minCount = arrayOfRepeats[l];
                    
                }
              
                
                
           

            }
            
            if(compareResult != 1){
                j = 0;
                numberOfLetters = 1;
                i++;
                wordCount++;
                numberOfStrings++;
                mainArray = realloc(mainArray, numberOfStrings * sizeof(char*));
                mainArray[i] = (char*)malloc(numberOfLetters * sizeof(char)+sizeof(char));
                arrayOfRepeats = realloc(arrayOfRepeats, numberOfStrings * sizeof(int*));
                arrayOfRepeats[i] = 1;
            }
             compareResult = 0;
        }
        
    }

    

    
    
    if(set == 1){
        int swaps;
        int tmp2;
        char *tmp3;
        for (int k = 0; k < wordCount-1; k++) {
            swaps = 0;
            for(int l = 0; l < wordCount-k-1; l++){
                if(arrayOfRepeats[l] > arrayOfRepeats[l+1]){
                    tmp2 = arrayOfRepeats[l];
                    arrayOfRepeats[l] = arrayOfRepeats[l+1];
                    arrayOfRepeats[l+1] = tmp2;
                    tmp3 = mainArray[l];
                    mainArray[l] = mainArray[l+1];
                    mainArray[l+1] = tmp3;
                    swaps++;
                }
            }
            
        }
        
    }
    
    if(set == 2){
        int swaps;
        int tmp2;
        char *tmp3;
        for (int k = 0; k < wordCount-1; k++) {
            swaps = 0;
            for(int l = 0; l < wordCount-k-1; l++){
                if(strcmp(mainArray[l], mainArray[l+1])>0){
                    tmp2 = arrayOfRepeats[l];
                    arrayOfRepeats[l] = arrayOfRepeats[l+1];
                    arrayOfRepeats[l+1] = tmp2;
                    tmp3 = mainArray[l];
                    mainArray[l] = mainArray[l+1];
                    mainArray[l+1] = tmp3;
                    swaps++;
                }
            }
            
        }
        
    }
    
    
    
    
    
    
    
    if (len != 0)   printf("Seznam slov:\n");
    if(len != -1){
      
    for(int n = 0; n < numberOfStrings-1; n++){
        if(strlen(mainArray[n]) == len){
        printf("%s", mainArray[n]);
        for (int k = 0; k < 21-strlen(mainArray[n]); k++){
            printf(" ");
           
        }
        printf("%d\n", arrayOfRepeats[n]);
        }
        if (arrayOfRepeats[n] == minCount){
            minWords[mn] = n;
            mn++;
        }
        if (arrayOfRepeats[n] == maxCount){
            
            maxWords[mx] = n;
            mx++;
        }
           }
    }
    else{
        for(int n = 0; n < numberOfStrings-1; n++){
                printf("%s", mainArray[n]);
                for (int k = 0; k < 21-strlen(mainArray[n]); k++){
                    printf(" ");
                }
                printf("%d\n", arrayOfRepeats[n]);
            if (arrayOfRepeats[n] == minCount){
                minWords[mn] = n;
                mn++;
            }
            if (arrayOfRepeats[n] == maxCount){
                maxWords[mx] = n;
                mx++;
            }
        }
    }
    
    

    
    
    
    printf("Pocet slov:          %d\n", wordCount);
    printf("Nejcastejsi:        ");
    for(int n = 0; n < mx; n++){
       printf(" %s", mainArray[maxWords[n]]);
        
    }
    printf("\n");
    
    printf("Nejmene caste:      ");
    for(int n = 0; n < mn; n++){
        int index = minWords[n];
        printf(" %s", mainArray[index]);
    }
    printf("\n");
    
    for(int n = 0; n < numberOfStrings; n++){
        free(mainArray[n]);
    }
           free(mainArray);
    free(arrayOfRepeats);
    
    
    
    
   /* int i;
    if( argc >= 2 )
    {
        printf("The arguments supplied are:\n");
        for(i = 1; i < argc; i++)
        {
            printf("%s\t", argv[i]);
        }
    }
    else
    {
        printf("argument list is empty.\n");
    } */
    return 0;
}


