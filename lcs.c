#include<stdio.h>
#include<string.h>
#define MAX 100

int dp[MAX + 1][MAX + 1];
int b[MAX + 1][MAX + 1];

int lcs(char *X, char *Y, int m, int n){
  for(int i = 0; i <= m; i++){
    for(int j = 0; j <= n; j++){
      if(i == 0 || j == 0) {
          dp[i][j] = 0;
      }
    }
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){

      if (X[i-1] == Y[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
        b[i][j] = 1;
      }

      else {
        if (dp[i-1][j] >= dp[i][j-1]){
          dp[i][j] = dp[i-1][j];
          b[i][j] = 2;
        }
        else{
          dp[i][j] = dp[i][j-1];
          b[i][j] = 3;
        }
      }
    }
  }
  return dp[m][n];
}

void print_lcs(char *X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == 1) {
        print_lcs(X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 2) {
        print_lcs(X, i - 1, j);
    }
    else {
        print_lcs(X, i, j - 1);
    }
}

int main(){
  char X[MAX];
  char Y[MAX];

  printf("Enter String X (no spaces): ");
  if (scanf("%s", X) != 1) return 1;

  printf("Enter String Y (no spaces): ");
  if (scanf("%s", Y) != 1) return 1;

  int m = strlen(X);
  int n = strlen(Y);

  if (m >= MAX || n >= MAX) {
      printf("\nError: Input string length exceeds MAX limit.\n");
      return 1;
  }

  int lcs_len = lcs(X,Y,m,n);

  printf("\n--- LCS Result ---\n");
  printf("String X: %s\n", X);
  printf("String Y: %s\n", Y);
  printf("The length of LCS is %d\n", lcs_len);

  printf("LCS Sequence: ");
  print_lcs(X, m, n);
  printf("\n");

  return 0;
}