#include<stdio.h>
#include<string.h>

void printarray(int arr[], int size){
	for(int i = 1; i <= size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void merge(int arr[], int l, int h, int mid){

	int n1 = mid - l + 1;
	int n2 = h - mid;
	int L1[n1 + 1];
	int L2[n2 + 1];
	for(int i = 1; i <= n1; i++){
    L1[i] = arr[l + i - 1];
	}
	for(int j = 1; j <= n2; j++){
		L2[j] = arr[mid + j];
	}
	L1[n1 + 1] = 999999999;
	L2[n2 + 1] = 999999999;

	int i = 1;
	int j = 1;
	for(int k = l; k <= h; k++){
		if(L1[i] <= L2[j]){
			arr[k] = L1[i];
			i++;
		}
		else{
			arr[k] = L2[j];
			j++;
		}
	}
}
void mergesort(int arr[], int l, int h){
	if(l < h){
		int mid = l + (h - l) / 2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, h);
		merge(arr, l, h, mid);
	}
}

int main(){
	int size;
	printf("Enter the size of array: ");
	scanf("%d", &size);
	int arr[size + 1];
  printf("Enter the elements of array:\n");
	for(int i = 1; i <= size; i++){
		scanf("%d", &arr[i]);
	}

	printf("Original Array: ");
	printarray(arr, size);
	mergesort(arr, 1, size);

	printf("Sorted Array: ");
	printarray(arr, size);

	return 0;
}