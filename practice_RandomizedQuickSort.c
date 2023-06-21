#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void swap(int *array, int low, int high){
    int temp;
    temp=array[low];
    array[low]=array[high];
    array[high]=temp;
}

int RandomizedPartition(int *array, int left, int right){
    int low, high, pivot_item, i;
    i=rand()%(right-left+1)+left;
    swap(array,left,i);
    low=left;
    high=right;
    pivot_item=array[left];
    while(low<high){
        while((low<=high) && (array[low]<=pivot_item)) low++;
        while((low<=high) && (array[high]>pivot_item)) high--;
        if(low<high){
            swap(array,low,high);
        }
    }
    array[left]=array[high];
    array[high]=pivot_item;
    return high;
}

void RandomizedQuickSort(int *array, int left, int right){
    int pivot;
    if(left<right){
        pivot=RandomizedPartition(array,left,right);
        RandomizedQuickSort(array,left,pivot-1);
        RandomizedQuickSort(array,pivot+1,right);
    }
}

int main(void){
    int array[10]={4,5,8,2,1,3,9,0,6,7};
    int temp[10];
    RandomizedQuickSort(array,0,9);

    for(int i=0; i<10; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    return 0;
}