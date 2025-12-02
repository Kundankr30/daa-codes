#include<stdio.h>
#include<stdlib.h>

int place(int k, int i);
void nqueens(int k, int n);

int x[101], count = 0;

int place(int k, int i){
    int j;

    for(j = 1; j < k; j++){

        if(x[j] == i) {
            return 0;
        }

        if(abs(x[j] - i) == abs(j - k)) {
            return 0;
        }
    }
    return 1;
}

void nqueens(int k, int n){
    int i;
    for(i = 1; i <= n; i++){
        if(place(k, i)){
            x[k] = i;

            if(k == n){
                count++;
                for(int j = 1; j <= n; j++){
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            else{
                nqueens(k + 1, n);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of queens (N) to be placed: ");
    scanf("%d", &n);

    nqueens(1, n);

    printf("\nTotal Solutions: %d\n", count);

    return 0;
}