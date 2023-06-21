void swap(int *array, int low, int high){
    int temp;
    temp=array[low];
    array[low]=array[high];
    array[high]=temp;
}

int Partition(int *array, int left, int right){
    int low, high, pivot_item;
    pivot_item=array[left];
    low=left;
    high=right;
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

void QuickSort(int *array, int left, int right){
    int pivot;
    if(left<right){
        pivot=Partition(array,left,right);
        QuickSort(array,left,pivot-1);
        QuickSort(array,pivot+1,right);
    }
}

int main(void){
    int array[10]={4,5,8,2,1,3,9,0,6,7};
    QuickSort(array,0,9);

    for(int i=0; i<10; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    return 0;
}