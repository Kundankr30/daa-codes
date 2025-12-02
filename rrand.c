#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printarray(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int p, int r) {
    // arr[r] is the pivot
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);

    return i + 1;
}
int partition_r(int arr[], int p, int r) {
    int random_index = p + rand() % (r - p + 1);
    swap(&arr[random_index], &arr[r]);
    return partition(arr, p, r);
}
void quicksort(int arr[], int p, int r) {

    if (p < r) {
        int q = partition_r(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}
int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }
    int arr[size + 1];
    printf("Enter the %d elements of array:\n", size);
    // Use 1-based indexing for input
    for (int i = 1; i <= size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("\nOriginal Array: ");
    printarray(arr, size);

    // Sort the array using 1-based indices from 1 to size
    quicksort(arr, 1, size);

    printf("Sorted Array: ");
    printarray(arr, size);

    return 0;
}