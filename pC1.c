//
//  test.c
//  
//
//  Created by Maria Nosova on 26/09/2019.
//


#include  <stdlib.h>
#include <stdio.h>
int a;
int b;


int main(void)
{
    scanf("%d %d", &a, &b);
    if (abs(a) > 10000 || abs(b) > 10000) {
        printf("Vstup je mimo interval!\n");
    }
    else {
        printf("Desitkova soustava: %d %d\n", a, b);
        printf("Sestnactkova soustava: %x %x\n", a, b);
        printf("Soucet: %d + %d = %d\n", a, b, a+b);
        printf("Rozdil: %d - %d = %d\n", a, b, a-b);
        printf("Soucin: %d * %d = %d\n", a, b, a*b);
        if (b == 0) {printf("Nedefinovany vysledek!\n");}
        else {
            printf("Podil: %d / %d = %d\n", a, b, a/b);
        }
        printf("Prumer: %0.1f\n", (a+b)/2.0 );
        
    }
    return 0;
}
