#include <stdio.h>

void InsertionSort(int *array, int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key=array[i];
        j=i-1;
        while(j>=0 && key<array[j]){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}