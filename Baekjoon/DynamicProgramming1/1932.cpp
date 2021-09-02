#include <iostream>
#include <algorithm>

using namespace std;

int T[501][501];
int dp[501][501];

int isSum(int row, int col) {
    if (row == 1) return T[1][1];
    if (dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = T[row][col] + max(isSum(row - 1, col), isSum(row - 1, col - 1));
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &T[i][j]);
            dp[i][j] = -1;
        }
    }

    dp[1][1] = T[1][1];

    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        isSum(n, i);
        if (tmp < dp[n][i]) tmp = dp[n][i];
    }
    printf("%d\n", tmp);
}