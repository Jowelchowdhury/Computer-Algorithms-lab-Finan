#include <stdio.h>
#include <string.h>
#define MAX 100
int lcs(char*X, char*Y, int m, int n) {
 int L[MAX][MAX];
 for (int i = 0; i <= m; i++) {
 for (int j = 0; j <= n; j++) {
 if (i == 0 || j == 0)
 L[i][j] = 0;
 else if (X[i - 1] == Y[j - 1])
 L[i][j] = L[i - 1][j - 1] + 1;
 else
 L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
 }
 }
 return L[m][n];
}
int main() {
 char X[MAX], Y[MAX];
 printf("Enter first string: ");
 scanf("%s", X);
 printf("Enter second string: ");
 scanf("%s", Y);
 int m = strlen(X);
 int n = strlen(Y);
 printf("Length of LCS: %d\n", lcs(X, Y, m, n));
 return 0;
}
