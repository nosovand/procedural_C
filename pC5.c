#include <stdio.h>


void printBaseAndFence();
void printBase();
void printRoof();
int height = 0;
int width = 0;
int fence = -1;
int main(){
    scanf("%d %d", &width, &height);
    if (height == width){
        scanf("%d", &fence);
    }
        if (height == 0 || width == 0 || (height == width && fence == -1)){
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    if(width <3 || width>69 || height<3 || height>69){
        fprintf(stderr, "Error: Vstup mimo interval!\n");
        return 101;
    }
    if (width%2 == 0){
        fprintf(stderr, "Error: Sirka neni liche cislo!\n");
        return 102;
    }
    if (height == width && (fence < 1 || fence >= height)){
        fprintf(stderr, "Error: Neplatna velikost plotu!\n");
        return 103;
    }
    
    printRoof();
    if (height == width) printBaseAndFence();
    else printBase();
    return 0;
}


void printRoof(){
    for(int i = 1; i <=(width-1)/2; i++){
        for(int prvniMezery = ((width-1)/2) - i; prvniMezery >= 0; prvniMezery--){
            printf(" ");
        }
        printf("X");
    if(i == 1) {
        printf("\n");
        continue;
    }
        for(int druhyMezery = 0; druhyMezery < i*2-3; druhyMezery++){
            printf(" ");
        }
        printf("X\n");
    }
}


void printBase(){
    for(int vyska = 1; vyska <= height; vyska++){
        printf("X");
        for(int sirka = 0; sirka < width-2; sirka++){
            if(vyska == 1 || vyska == height){
                printf("X");
            }
            else {
                printf(" ");
            }
        }
        printf("X\n");
    }
    
}


void printBaseAndFence(){
    for(int vyska = 1; vyska <= height; vyska++){
        printf("X");
        
        for(int sirka = 0; sirka < width-2; sirka++){
            if(vyska == 1 || vyska == height){
                printf("X");
            }
            else if (vyska%2 == 0 && sirka %2 == 0){
                printf("o");
            }
            else if (vyska%2 == 0 && sirka %2 == 1){
                printf("*");
            }
            else if (vyska%2 == 1 && sirka %2 == 0){
                printf("*");
            }
            else if (vyska%2 == 1 && sirka %2 == 1){
                printf("o");
            }
        }
        printf("X");
        if (height-vyska >= fence){
            printf("\n");
        }
        if (height - vyska < fence){
            if (fence %2 == 0){
            for (int sirkaPlotu = 1; sirkaPlotu <= fence; sirkaPlotu++){
                if((height - vyska+1 == fence || vyska == height) && sirkaPlotu%2 == 1){
                    printf("-");
                }
                else if (sirkaPlotu%2 == 1){
                    printf(" ");
                }
            if (sirkaPlotu%2 == 0){
                printf("|");
            }
            
        }
            printf("\n");
    }
            
            if (fence %2 == 1){
                for (int sirkaPlotu = 1; sirkaPlotu <= fence; sirkaPlotu++){
                    if((height - vyska+1 == fence || vyska == height) && sirkaPlotu%2 == 0){
                        printf("-");
                    }
                    else if (sirkaPlotu%2 == 0){
                        printf(" ");
                    }
                    if (sirkaPlotu%2 == 1){
                        printf("|");
                    }
                    
                }
                printf("\n");
            }
        }
}
}
