#include <stdio.h>
#include <stdlib.h>

int compare(const void *b, const void *d){
    int p = *(const int *)b;
    int q = *(const int *)d;
    
    return (p-q);
}


int arrayLenght = 1;
int* array;
float median = 0.0;
int min, max;
int numberOfColumns;
int firstIndex = 0;
int main(){
    scanf("%d", &numberOfColumns);
    array = (int*)malloc(arrayLenght * sizeof(int));
    while(scanf("%d", array + firstIndex)>0){
        if(firstIndex == 0){
            min = array[0];
            max = array[0];
        }
        else{
            if(array[firstIndex]<min) min = array[firstIndex];
            if(array[firstIndex]>max) max = array[firstIndex];
        }
        firstIndex++;
            array = realloc(array, firstIndex*sizeof(int)+sizeof(int));
        
    }
    
    qsort(array, firstIndex, sizeof(int), compare); //serazeni
    if(firstIndex % 2 == 0){
        median = ((float)array[(firstIndex)/2-1]+(float)array[firstIndex/2])/2.0;
    }
    else median = (float)array[(firstIndex+1)/2-1];
    

   
     printf("Median %.2f\n", median);
     printf("Number count: %d\n", firstIndex);
     printf("Min: %d\n", min);
     printf("Max: %d\n", max);
    
    float interval = (float)(max - min)/(float)numberOfColumns;
    

    
    
   
    int maxValue = 0;
    int arrayOfValues[numberOfColumns];
    arrayOfValues[0] = 0;
    int a = 0;
    int secondIndex = 0;
    for (int i = 0; i < numberOfColumns; i++) {
        for (int j = 0; a+j<firstIndex; j++) {
            if((float)array[a+j] <= min + (float)(i+1) * interval){
                arrayOfValues[i]++;
                if(arrayOfValues[i]>maxValue) maxValue = arrayOfValues[i];
               // printf("array[%d] = %d < %f, [%d] = %d\n", a+j, min+ array[a+j],(float)(i+1) * interval, i, arrayOfValues[i]);
                secondIndex++;
            }
            else{
                a = secondIndex;
                break;
            }
        }
        if((i +1)<numberOfColumns) arrayOfValues[i+1] = 0;
    }
    
    
    
  /*  for (int k = 0; k < firstIndex; k++) {
        
        if((float)array[k] < ((float)min + ((float)a * interval))){
            arrayOfValues[a-1]++;
            printf("if interval %f, hodnota %d\n", ((float)min + ((float)a * interval)), arrayOfValues[k]);
        }
        else{
            int l;
            for (l = 0; l < numberOfColumns; l++) {
                if((float)array[k]>((float)l*interval)) continue;
                else {
                    arrayOfValues[l] = 1;
                }
                printf("else interval %f, hodnota %d, l = %d\n", ((float)min + ((float)a * interval)), arrayOfValues[k], l);
                a = l;
                break;
            }
            
            }
    }
*/
    
    float zacatek = (float)min;
    printf("Histogram:\n");
    for(int i = 0; i<numberOfColumns; i++){
        float konec = zacatek + interval;
        printf("%5.1f - %5.1f|", zacatek, konec);
        int k;
        for (k = 0; k < (int)((25.0/(float)maxValue) * (float)arrayOfValues[i]); k++) {
            printf("=");
        }
        printf("\n");
        zacatek = konec;
        
        
    }
    free(array);
    
return 0;
}
