#include<stdio.h>

//Example of transpose
void display(int arr[],int n){ 
	int i;
    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");  
}
//Deletion
void PositionDeletion(int arr[], int size, int pos){
	int i;
	for(i=pos;i<size-1;i++){
		arr[i] = arr[i+1];
	}
}

void BegningDeletion(int arr[], int size){
	int i;
	for(i=0; i<size-1; i++){
		arr[i] = arr[i+1];
	}
}

int main(){
	int arr[100] = {7, 8, 12, 27, 88};
	int size = 5;
	
	display(arr, size);
	
	PositionDeletion(arr, size, 2);
	size--;
	display(arr, size);
	
	BegningDeletion(arr, size);
	size--;
	display(arr, size);
	
	return 0;
}
