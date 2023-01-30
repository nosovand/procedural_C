
#include <stdio.h>

void characterShift(char codedText[], int changedText[]);
void characterCheck(int changedText[], int heardText[]);


int arrayLength;
int realLength;
int currentShift = 0;
int bestMatch = 0;
int maxLetters = 0;
int correctLetters = 0;
char scannedLetter;

int main(){
    
    scanf("%i", &arrayLength);
    char codedText[arrayLength-1], heardText[arrayLength-1];
int intHeardText[arrayLength-1];
    int changedText[arrayLength-1];
    for (int letters = -1; letters < arrayLength ; letters++){
        scanf("%c", &scannedLetter);
        if (scannedLetter == '\n') continue;
        if((scannedLetter >= 'A' && scannedLetter <= 'Z') || (scannedLetter >= 'a' && scannedLetter <= 'z') ){
        realLength++;
        codedText[letters] = scannedLetter;
    }
        
        else {
            fprintf(stderr, "Error: Chybny vstup!");
            return 100;
        }
    }
    if (realLength < arrayLength) {
        fprintf(stderr, "Error: Chybna delka vstupu!");
        return 101;
    }
    
    
    
    for (int secondLetters = -1; secondLetters < arrayLength; secondLetters++) {
        scanf("%c", &scannedLetter);
        if (scannedLetter == '\n') continue;
        heardText[secondLetters] = scannedLetter;
    }
    
    
    
    
    for (int letters = -1; letters < arrayLength ; letters++){
        intHeardText[letters] = heardText[letters];
    }
    
    
    
    

    
    
    for (int i = 0; i < 52; i++){
    currentShift = i;
    characterShift(codedText, changedText);
    characterCheck(changedText, intHeardText);

        for (int i = 0; i < arrayLength; i++){
        }
        }
   
    currentShift = bestMatch;
    characterShift(codedText, changedText);
    
    for (int i = 0; i < arrayLength; i++){
        printf("%c",changedText[i]);
    }
    printf("\n");
    return 0;
}


void characterShift(char codedText[], int changedText[]){
    for(int letter = 0; letter < arrayLength; letter++){
        changedText[letter]  =  codedText[letter] +currentShift;
            
        if (codedText[letter] >= 'A' && codedText[letter] <= 'Z' && changedText[letter] > 'Z' && changedText[letter] <= 't'){
            changedText[letter] = codedText[letter] + currentShift + 6;
        }
        
        else if (codedText[letter] >= 'A' && codedText[letter] <= 'Z' && changedText[letter] > 't' && currentShift <= 26){
            changedText[letter] = 64 + changedText[letter] + 6 - 122;
        }
        
        else if (codedText[letter] >= 'A' && codedText[letter] <= 'Z' && changedText[letter] > 't' && currentShift > 26){
            changedText[letter] = 64 + changedText[letter] - 116;
        }
        
        
        if (codedText[letter] >= 'a' && codedText[letter] <= 'z' && changedText[letter] > 'z' && changedText[letter]-122 <= 26){
            changedText[letter] = 64 + changedText[letter] - 122;
        }
            
        else if (codedText[letter] >= 'a' && codedText[letter] <= 'z' && changedText[letter] > 'z' && changedText[letter]-122 > 26){
            changedText[letter] = 96 + changedText[letter] - 122 - 26;
        }
            
            
        
       /* else {
            
            if (codedText[letter] >= 'A' && codedText[letter] <= 'Z' && codedText[letter] < ){
                changedText[letter] = ;
            }
            
            
        }
        
        
        
        if (codedText[letter] >= 'a' && codedText[letter] <= 'z' && changedText[letter] > 148){
            changedText[letter] = 97 + changedText[letter] - 122 - 27;
            continue;
        }
        else if (codedText[letter] >= 'a' && codedText[letter] <= 'z' && changedText[letter] > 'z'){
            changedText[letter] = 64 + changedText[letter] - 122;
            continue;
      */
        
        
        
      /* if (changedText[letter] > 122){
            
            changedText[letter] = (64+codedText[letter]+currentShift)-122;
            
        }
        if (changedText[letter] > 'Z' && changedText[letter] < 'a'){
            changedText[letter] = (96+changedText[letter])-90;
        }
       */
    }
}

void characterCheck(int changedText[], int heardText[]){
    correctLetters = 0;
    for (int letter = 0; letter < arrayLength; letter++){
        int a = changedText[letter];
        int b = heardText[letter];
        if (a == b) {
            correctLetters +=1;
                    }
    }
    if (correctLetters > maxLetters){
        maxLetters = correctLetters;
        bestMatch = currentShift;
    }
}



