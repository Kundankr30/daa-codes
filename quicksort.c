#include<stdio.h>

// Prints the array elements from index 1 to size
void printarray(int arr[], int size) {
    // Loop starts at i = 1 and goes up to i <= size
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Partition logic operates on 1-based indices
int partition(int arr[], int p, int r) {
    // arr[r] is the pivot
    int pivot = arr[r];
    int i = p - 1; // i is the index of the last element less than or equal to pivot

    // j iterates from p up to r-1
    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivot (arr[r]) with the element at i + 1
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1; // Return the pivot's final index
}


void quicksort(int arr[], int p, int r) {

    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Declare array of size+1 to use indices 1 through size. Index 0 is unused.
    int arr[size + 1];

    printf("Enter the elements of array:\n");
    // Use 1-based indexing for input
    for (int i = 1; i <= size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printarray(arr, size);

    // Sort the array using 1-based indices from 1 to size
    quicksort(arr, 1, size);

    printf("Sorted Array: ");
    printarray(arr, size);

    return 0;
}