#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void Merge(int A[],int temp[], int left, int right, int right_end){
	int i, j, left_end, size, temp_pos;
	left_end=right-1;
	size=right_end-left+1;
	i=left;
	j=right;
	temp_pos=left;
	
	while((i<=left_end)&&(j<=right_end)){
		if(A[i]<=A[j]){
			temp[temp_pos]=A[i];
			temp_pos+=1;
			i+=1;
		}else{
			temp[temp_pos]=A[j];
			temp_pos+=1;
			j+=1;
		}
	}
	
	while(i<=left_end){
		temp[temp_pos]=A[i];
		temp_pos+=1;
		i+=1;
	}

	while(j<=right_end){
		temp[temp_pos]=A[j];
		temp_pos+=1;
		j+=1;
	}

	for(i=left; i<=right_end; i++){
		A[i]=temp[i];
	}
}

void MergeSort(int A[], int temp[], int left, int right){
	int mid; 
    mid=(left+right)/2;
	if(left<right){
		MergeSort(A,temp,left,mid);
		MergeSort(A,temp,mid+1,right);
		Merge(A,temp,left,mid+1,right);
	}
}

int main(void){
    int temp[30];
    int array[30];
    int i;
    for(i=0; i<30; i++){
        array[i]=rand()/(RAND_MAX/30);
        printf("%d ",array[i]);
    }
    printf("\n");

    MergeSort(array,temp,0,29);

    for(i=0; i<30; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    return 0;
}