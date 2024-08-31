#include<stdio.h>
//Example of transpose
void display(int arr[],int n){ 
	int i;
    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");  
}
//insertion 
void PositionInsertion(int arr[], int size, int element, int pos){ 
	int i;
	for(i = size; i>=pos; i--){
		arr[i+1] = arr[i];
	}
	arr[pos] = element;
}

void BegningInsertion(int arr[], int size, int element){
	int i;
	for(i=size; i>=0; i--){
		arr[i+1] = arr[i];
	}
	arr[0] = element;
}

void SortedInsertion(int arr[], int size, int element){
	int i;
	for(i = size-1; i>=0 && arr[i]>element; i--){
		arr[i+1] = arr[i];
	}
	arr[i+1] = element;
}

int main(){
    int arr[100]={7, 8, 12, 27, 88};
    int size = 5;
    
    display(arr, size);
    
    PositionInsertion(arr, size, 45, 4);
    size++;
    display(arr, size);
    
    BegningInsertion(arr, size, 3);
    size++;
    display(arr, size);
    
    SortedInsertion(arr, size, 35);
    size++;
    display(arr, size);
    
   return 0;
}
