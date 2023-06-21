#include <stdio.h>

void SelectionSort(int *array, int n){
    int i,j,min,temp;
    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(array[j]<array[min]) min=j;
        }
        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
}