#include<stdio.h>
#include<limits.h>

int m[50][50];
int s[50][50];

void matrix_chain_order(int p[], int n){
    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = 99999;

            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];

                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parenthesis(int i, int j){
    if(i == j){
        printf("A%d", i);
    }
    else{
        printf("(");
        print_optimal_parenthesis(i, s[i][j]);
        print_optimal_parenthesis(s[i][j] + 1, j);
        printf(")");
    }
}

int main(){
    int n;
    printf("Enter the no of matrices (n): ");
    scanf("%d", &n);

    int p[10];
    printf("Enter the %d elements of the dimension array p (p[0]...p[n]):\n", n + 1);
    for(int i = 0; i <= n; i++){
        scanf("%d", &p[i]);
    }

    matrix_chain_order(p, n);

    printf("\n--- M Table (Minimum Cost) ---\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (i <= j) {
                printf("%d\t", m[i][j]);
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }

    printf("\n--- S Table (Optimal Split Point) ---\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
             if (i < j) {
                printf("%d\t", s[i][j]);
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }

    printf("\n--- Optimal Parenthesization ---\n");
    print_optimal_parenthesis(1, n);
    printf("\n");

    printf("\nMinimum scalar multiplications required: %d\n", m[1][n]);

    return 0;
}