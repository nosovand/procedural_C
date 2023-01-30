#include <stdio.h>
#include <stdlib.h>

int main(){
    int inputNumber;
    int index = 0;
    int numberOfPositiveNumbers = 0;
    int numberOfNegativeNumbers = 0;
    int numberOfEvenNumbers = 0;
    int numberOfOddNumbers = 0;
    int totalSum = 0;
    int max = -10000;
    int min = 10000;
    while(scanf("%i",&inputNumber) > 0){
        if (abs(inputNumber) > 10000) {
            printf("\nError: Vstup je mimo interval!");
            break;
        }
        else
            (index == 0) ? index ++: printf(", "), index++;
        printf("%i", inputNumber);
        if (inputNumber > 0){
            numberOfPositiveNumbers++;
        }
        if (inputNumber < 0){
            numberOfNegativeNumbers++;
        }
        if (inputNumber %2 == 0){
            numberOfEvenNumbers++;
        }
        if (inputNumber %2 != 0) {
            numberOfOddNumbers++;
        }
        totalSum = totalSum + inputNumber;
        
        (inputNumber>max) ? max = inputNumber : max ;
        (inputNumber<min) ? min = inputNumber : max ;
}
    printf("\n");
    if (abs(inputNumber) > 10000) {
         return 100;
    }
    else{
    printf("Pocet cisel: %i\n", index-1);
    printf("Pocet kladnych: %i\n", numberOfPositiveNumbers);
    printf("Pocet zapornych: %i\n", numberOfNegativeNumbers);
    printf("Procento kladnych: %.2f\n", 100*(double)numberOfPositiveNumbers/(index-1));
    printf("Procento zapornych: %.2f\n", 100*(double)numberOfNegativeNumbers/(index-1));
    printf("Pocet sudych: %i\n", numberOfEvenNumbers);
    printf("Pocet lichych: %i\n", numberOfOddNumbers);
    printf("Procento sudych: %.2f\n", 100*(double)numberOfEvenNumbers/(index-1));
    printf("Procento lichych: %.2f\n", 100*(double)numberOfOddNumbers/(index-1));
    printf("Prumer: %.2f\n", (double)totalSum/(index-1));
    printf("Maximum: %i\n", max);
    printf("Minimum: %i\n", min);
        return 0;
    }
}
