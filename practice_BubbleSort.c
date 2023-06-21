#include <stdio.h>

void BubbleSort(int *array, int n){
    for(int pass=n-1; pass>0; pass--){
        for(int i=0; i<pass; i++){
            if(array[i+1]<array[i]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
}

void BubbleSortEdit(int *array, int n){
    int swapped=1; //adaptability 향상,
    for(int pass=n-1; pass>0 && swapped; pass--){
        swapped=0;
        for(int i=0; i<pass; i++){
            if(array[i+1]<array[i]){
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
                swapped=1;
            }
        }
    }
}