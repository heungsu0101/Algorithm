#include <iostream>

using namespace std;

int dp[1003] = {1, 2, };

int isNumber(int N) {
    if (N == 1) return 1;
    if (N == 2) return 2;
    if (dp[N] != 0) return dp[N];
    return dp[N] = (isNumber(N - 1) + isNumber(N - 2)) % 10007;
}

int main() {
    int N; scanf("%d", &N);
    printf("%d\n", isNumber(N));
}