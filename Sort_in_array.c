 #include<stdio.h>
 
//Example of transpose
void display(int arr[],int n){ 
	int i;
    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");  
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*x = temp;
}

void SelectionSort(int arr[], int size){
	int i,j;
	for(i=0; i<size-1; i++){
		int min_idx = i;
		for(j=i+1; j<size; j++){
			if(arr[j] < arr[min_idx]){
				min_idx = j;
			}
		}
		if(min_idx != i){
			swap(&arr[min_idx], &arr[i]);
		}
	}
}

void BubbleSort(int arr[], int size){
	int i,j;
	for(i=0; i<size-1; i++){
		for(j= i+1; j<size; j++){
			if(arr[j] < arr[i]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void InsertionSort(int arr[], int size){
	int i, j;
	for(i=0; i<size; i++){
		int key = arr[i];
		for(j =i-1; j>=0 && arr[j]>key; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
	}
}

void QuickSort(int arr[], int size){
	
}

int main(){
    int arr[]={3, 15, 7, 25, 11, 20};
    int size = sizeof(arr)/sizeof(int);
    
    display(arr, size);
    
    
//    BubbleSort(arr, size);
//    display(arr, size);
    
//    SelectionSort(arr, size);
//    display(arr, size);
    
    InsertionSort(arr, size);
    display(arr, size);
    
    
    return 0;
}
