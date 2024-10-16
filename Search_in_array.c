#include<stdio.h>

// Search
int LinearSearch(int arr[], int size, int element){
	int i;
	for(i=0; i<size; i++){
		if(arr[i] == element){
			return i;
		}
	}
	return -1;
}

int BinarySearch(int arr[], int size, int element){
	int low = 0;
	int mid;
	int high = size-1;
	
	while(low<=high){
		mid = (low + high)/2;
		if(arr[mid] == element){
			return mid;
		}
		if(arr[mid]<element){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return -1;
}

int min(int x, int y) { return (x <= y) ? x : y; }

int FibonacciSearch(int arr[], int size, int element){
	int i;
	int F2 = 0;
	int F1 = 1;
	int F = F2 + F1;
	
	int offset = -1;
	
	while(F < size){
		F2 = F1;
		F1 = F;
		F = F2 + F1;
	}
	
	while(F1 > 1){
		i = min(offset + F2, size -1);
		
		if (arr[i] < element) {
            F = F1;
            F1 = F2;
            F2 = F - F1;
            offset = i;
        }
        else if (arr[i] > element) {
            F = F2;
            F1 = F1 - F2;
            F2 = F - F1;
    	}
        else{
            return i;
    	}
	}
	if (F1 && arr[offset + 1] == element){
        return offset + 1;
    }
    
    return -1;
}

int main(){
	int arr[] = {2,5,9,23,45,79};
	int size = sizeof(arr)/sizeof(int);
	int element = 23;
	
//	int searchindex = LinearSearch(arr, size, element);
//	printf("The element %d is found in %d index\n",element,searchindex);
	
//	int searchindex = BinarySearch(arr, size, element);
//	printf("The element %d is found in %d index\n",element,searchindex);
	
	int searchindex = FibonacciSearch(arr, size, element);
	printf("The element %d is found in %d index\n",element,searchindex);
	
	return 0;
}
