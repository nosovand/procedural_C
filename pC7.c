#include <stdio.h>
#include <stdlib.h>

void nasobeni(int maticeJedna[], int maticeDva[], int vysledek[]);
void scitani (int maticeJedna[], int maticeDva[]);
void odcitani (int maticeJedna[], int maticeDva[]);
int nactiMatici();
int nactiZnamenko();


int fstRadky = 0, fstSloupce = 0;
int fstRealnaVelikost = 0, scdRealnaVelikost = 0;
int scdRadky = 0, scdSloupce = 0;
int velikostDruheMatice;
int velikostVysledneMatice = 0;
int radky[110], sloupce[110];
int matice[110] [100000];
int indexPrvnihoNacitani = 0;
int velikostMatice = 0;
char znamenko[110];
int pocetMatic = 0;
int vysledek[100000];
int b[100000];
int radkyVysledneMatice = 0;
int sloupceVysledneMatice = 0;

    //int velikostDruheMatice = scdSloupce*scdRadky;
/* The main program */




int main(int argc, char *argv[])
{
    
/*    scanf("%d %d", &fstRadky, &fstSloupce);
    int velikostPrvniMatice = fstSloupce * fstRadky;
    int prvniMatice[velikostPrvniMatice];
    for (int i=0;i<velikostPrvniMatice; i++){
        if(scanf("%d", &prvniMatice[i])>0){
            fstRealnaVelikost++;
        }
        else break;
    }
    
    if (fstRealnaVelikost != velikostPrvniMatice){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    
    
    for (int i = 0; i < 1;){
    scanf("%c", &znamenko);
        if (znamenko == ' ' || znamenko == '\n'){
            continue;
        }
        else break;
    }
    
   
    
    scanf("%d %d", &scdRadky, &scdSloupce);
    velikostDruheMatice = scdSloupce * scdRadky;
    int druhaMatice[velikostDruheMatice];
    for (int i=0;i<velikostDruheMatice; i++){
        if(scanf("%d", &druhaMatice[i])>0){
            
            scdRealnaVelikost++;
        }
    }
    if (scdRealnaVelikost != velikostDruheMatice){
        
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
 
 */
    int turnOff = 0;
    if (nactiMatici() == 100){
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }
    pocetMatic++;
    while (turnOff == 0) {
        nactiZnamenko();
  
        if (znamenko[indexPrvnihoNacitani] != '*' && znamenko[indexPrvnihoNacitani] != '+' && znamenko[indexPrvnihoNacitani] != '-' ){
            break;
            
        }
      
        if(znamenko[indexPrvnihoNacitani] == '*'){
           
            indexPrvnihoNacitani++;
            nactiMatici();
            if(sloupce[indexPrvnihoNacitani-1] == radky[indexPrvnihoNacitani]){
                velikostVysledneMatice = radky[indexPrvnihoNacitani-1]*sloupce[indexPrvnihoNacitani];
                nasobeni(matice[indexPrvnihoNacitani-1], matice[indexPrvnihoNacitani], vysledek);
                indexPrvnihoNacitani--;
            }
            else{
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
           
        }
        
        else if(znamenko[indexPrvnihoNacitani] == '+' || znamenko[indexPrvnihoNacitani] == '-'){
            
            indexPrvnihoNacitani++;
            nactiMatici();
            pocetMatic++;
        }
        
        
    }
    

    
    for(int i = 1; i < pocetMatic; i++){
        if(radky[i-1] == radky[1] && radky[i-1] == radky[i]){
            
            if (znamenko[i-1] == '+'){
                radkyVysledneMatice = radky[i];
                sloupceVysledneMatice = sloupce[i];
                velikostVysledneMatice = radky[i]*sloupce[i];
                scitani(matice[i-1], matice[i]);
               
                for(int j = 0; j < velikostVysledneMatice; j++){
                    b[j] = matice[i][j];
                    vysledek[j] = b[j];
                    
            }
            }
                
            if (znamenko[i-1] == '-'){
                radkyVysledneMatice = radky[i];
                sloupceVysledneMatice = sloupce[i];
                velikostVysledneMatice = radky[i]*sloupce[i];
                odcitani(matice[i-1], matice[i]);
                for(int j = 0; j < velikostVysledneMatice; j++){
                    b[j] = matice[i][j];
                     vysledek[j] = b[j];
                    
                
            }
        }
        
        
        }
        else {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
    }
    
    
    
    //test
   
  
/*
    switch (znamenko) {
        case '*':
            if(fstSloupce == scdRadky){
            velikostVysledneMatice = fstRadky*scdSloupce;
            nasobeni( prvniMatice,  druhaMatice,  vyslednaMatice);
            }
            else {
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
            break;
        case '+':
            if(fstSloupce == scdSloupce && fstRadky == scdRadky){
                velikostVysledneMatice = velikostPrvniMatice;
            }
            else {
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
            scitani(prvniMatice, druhaMatice, vyslednaMatice);
            break;
        case '-':
            if(fstSloupce == scdSloupce && fstRadky == scdRadky){
                velikostVysledneMatice = velikostPrvniMatice;
            }
            else {
                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
            odcitani(prvniMatice, druhaMatice, vyslednaMatice);
            break;
        default:
            velikostVysledneMatice = 0;
            break;
    }
  
            int index = 0;
            printf("%d %d\n", fstRadky, scdSloupce);
            for (int i=0;i<velikostVysledneMatice; i++){
                printf("%i", vyslednaMatice[i]);
                index++;
                if (index == scdSloupce){
                    index = 0;
                    printf("\n");
                }
                else printf(" ");
            }
    return 0;

 
*/
    
    
    int index = 0;
    printf("%d %d\n", radkyVysledneMatice, sloupceVysledneMatice);
    for (int i=0;i<velikostVysledneMatice; i++){
        printf("%i", vysledek[i]);
        index++;
        if (index == sloupceVysledneMatice){
            index = 0;
            printf("\n");
        }
        else printf(" ");
    }
    return 0;
}

void nasobeni(int maticeJedna[], int maticeDva[], int vysledek[]) {
    velikostDruheMatice = radky[indexPrvnihoNacitani]*sloupce[indexPrvnihoNacitani];
    fstRadky = radky[indexPrvnihoNacitani-1];
    scdSloupce = sloupce[indexPrvnihoNacitani];
    fstSloupce = sloupce[indexPrvnihoNacitani-1];
    scdRadky = radky[indexPrvnihoNacitani];
    sloupce[indexPrvnihoNacitani-1] = scdSloupce;
    radkyVysledneMatice = radky[indexPrvnihoNacitani-1];
    sloupceVysledneMatice = scdSloupce;
    
    
    int test[velikostDruheMatice];
    for (int i = 0; i < velikostDruheMatice; i++){
        test[i] = maticeDva[i];
    }
    int promennaMatice[fstRadky*scdSloupce];
    int momentalniPrvek = 0;
    int indexPrvniMatice = 0;
    int indexDruheMatice = 0;
    for(int prvekMatice = 0; prvekMatice<velikostVysledneMatice;){
    for (int radkyPrvni = 0; radkyPrvni < fstRadky; radkyPrvni++){
        for (int sloupceDruhe = 0; sloupceDruhe < scdSloupce; sloupceDruhe++) {
            for (int sloupcePrvni = 0; sloupcePrvni < fstSloupce; sloupcePrvni++){
        
                
        indexPrvniMatice = radkyPrvni*fstSloupce+sloupcePrvni;
        indexDruheMatice = sloupcePrvni*scdSloupce+sloupceDruhe;
        momentalniPrvek +=  test[indexDruheMatice] * maticeJedna[indexPrvniMatice];
            
            
            }
            promennaMatice[prvekMatice] = momentalniPrvek;
            momentalniPrvek = 0;
            prvekMatice++;
    }
        
        
    }

}
    for (int i = 0; i < fstRadky*scdSloupce; i++){
        matice[indexPrvnihoNacitani-1] [i] = promennaMatice[i];
    }
    for (int i = 0; i < fstRadky*scdSloupce; i++){
        vysledek[i] = promennaMatice[i];
    }
}



void scitani (int maticeJedna[], int maticeDva[]) {
    
    for (int i = 0; i < velikostVysledneMatice; i++){
        maticeDva[i] = maticeJedna[i] + maticeDva[i];
    }
}

void odcitani (int maticeJedna[], int maticeDva[]) {
   
    for (int i = 0; i < velikostVysledneMatice; i++){
        maticeDva[i] = maticeJedna[i] - maticeDva[i];
    }
}

int nactiMatici(){
    scanf("%d %d", &radky[indexPrvnihoNacitani], &sloupce[indexPrvnihoNacitani]);
    int velikostMatice = radky[indexPrvnihoNacitani] * sloupce[indexPrvnihoNacitani];
    for (int i=0;i<velikostMatice; i++){
        if(scanf("%d", &matice[indexPrvnihoNacitani][i])>0){
            fstRealnaVelikost++;
        }
        else break;
    }
    

    int a = fstRealnaVelikost;
    if (a != velikostMatice && a != 0){
        return 100;
    }
    
    fstRealnaVelikost = 0;
    velikostMatice = 0;
    return 0;
}
    
    
int nactiZnamenko(){
    int rtr = 1;
      for (int i = 0; i < 10; i++){
        scanf("%c", &znamenko[indexPrvnihoNacitani]);
        if (znamenko[indexPrvnihoNacitani] == ' ' || znamenko[indexPrvnihoNacitani] == '\n'){
            rtr = 0;
            continue;
            
        }
        else{
            rtr = 5;
            break;
            
        }
    }
    return rtr;
}
