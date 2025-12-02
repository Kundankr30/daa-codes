#include<stdio.h>
int heapsize;
int left(int i){
    return 2 * i;
}
int right(int i){
    return (2 * i) + 1;
}
int parent(int i){
    return i/2;
}
void maxHepify(int A[], int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= heapsize && A[l] > A[largest]){
        largest = l;
    }
    if(r <= heapsize && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHepify(A,largest);
    }
}
void buildMaxHeap(int A[], int n){
    heapsize = n;
    for(int i = n/2; i >= 1; i--){
        maxHepify(A,i);
    }
}
int heapMax(int A[]){
    return A[1];
}
int heapExtractMax(int A[]){
    if(heapsize < 1){
        printf("Heap Underflow\n");
        return -1;
    } else {
        int max = A[1];
        A[1] = A[heapsize];
        heapsize--;
        maxHepify(A,1);
        return max;
    }
}
void heapIncreaseKey(int A[], int i, int key){
    if(key < A[i]){
        printf("New key is smaller than the current key\n");
        return ;
    }
    A[i] = key;
    while(i > 1 && A[parent(i)] < A[i]){
        int temp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = temp;
        i = parent(i);
    }
}
void maxHeapInsert(int A[], int key){
    heapsize++;
    A[heapsize] = -99999;
    heapIncreaseKey(A,heapsize,key);
}
void heapsort(int A[20], int n){
    buildMaxHeap(A,n);
    for(int i = n; i >= 2; i--){
        int temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heapsize--;
        maxHepify(A,1);
    }
}
int main(){
    int A[20],n;
    printf("Enter the no. of elements : \n");
    scanf("%d",&n);
    int i;
    printf("Enter %d elements: ",n);
    for(i = 1; i <= n; i++){
        scanf("%d",&A[i]);
    }
    //heapsort(A,n);
    buildMaxHeap(A,n);
    //printf("Max element : %d\n",heapMax(A));
    //printf("Extracted Max : %d\n",heapExtractMax(A));
    //axHeapInsert(A,20);
    //printf("After inserting 20 New max heap : %d\n",heapMax(A));
    heapsort(A,n);
    printf("Sorted Array \n");
    for(i = 1; i <= n; i++){
        printf("%d ",A[i]);
    }
    return 0;
}