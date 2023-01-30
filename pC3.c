#include <stdio.h>
#include <stdlib.h>

void printSequence();
void chybnyVystup();
int letterCheck();
char runningLetter = 'a', currentSequence = 'b';
double compression = 0.0;
int error = 0;
int sequenceCount = 0, letterCount = 0, codedLetters = 0;
/* The main program */
int main()
{

    while (scanf("%c", &runningLetter)>0) {
        if (letterCheck() == 1) letterCount++; //pokud je pismeno A-Z, tak se pricita jedno pismeno
        if (sequenceCount < 255){ //pokud mensi 255, probiha cyklus psani
        if (letterCount == 1 && letterCheck() == 1){
            currentSequence = runningLetter;
        }
        if (runningLetter == currentSequence) {
            sequenceCount++;
        }
       if (letterCheck() == 1) {
            printSequence();
            
            currentSequence = runningLetter;
        }
        if (letterCheck() == 0) {
            error = 1;
            break;
        }
    }
        else{ printSequence();
        }
    }
    
    
    if (letterCount == 1) {
      printf("%c", currentSequence);
        codedLetters += 1;
    }
    else printSequence();
    

     if (scanf("%c", &runningLetter) != 1){
   printf("\n");
    compression = (double)codedLetters/(double)letterCount;
    chybnyVystup();
             return 0;
}
     else {
         fprintf(stderr, "Error: Neplatny symbol!\n");
         return 100;
     }

// TODO - insert your code here
}

void printSequence() {
    
    if (letterCount > 0 && runningLetter != currentSequence){
        if (sequenceCount == 1) {
            printf("%c", currentSequence);
            codedLetters += 1;
        }
        if (sequenceCount == 2){
            printf("%c%c", currentSequence, currentSequence);
            codedLetters += 2;
        }
        if (sequenceCount > 2 && sequenceCount < 255) {
            printf("%c%i", currentSequence, sequenceCount);
            if (sequenceCount < 10) codedLetters += 2;
            else if (sequenceCount < 100) codedLetters += 3;
            else codedLetters +=4;
        }
        if (sequenceCount == 255) {
            printf("%c255", currentSequence);
            codedLetters +=4;
        }
        sequenceCount = 1;
        
    }
    
        }

void chybnyVystup(){
    fprintf(stderr, "Pocet vstupnich symbolu: %i\n", letterCount);
    fprintf(stderr, "Pocet zakodovanych symbolu: %i\n", codedLetters);
    fprintf(stderr, "Kompresni pomer: %.2f\n", compression);
    
}

int letterCheck() {
    if (runningLetter >= 'A' && runningLetter <= 'Z') return 1;
    else return 0;
}
