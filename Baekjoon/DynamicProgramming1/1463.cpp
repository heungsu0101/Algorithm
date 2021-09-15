#include <iostream>

using namespace std;

int dp[1000006];

int iscnt(int N) {
    if (dp[N] != 1000006) return dp[N];
    if (N == 1) return 0;
    dp[N] = iscnt(N - 1) + 1;
    if (N % 3 == 0) {
        int tmp = iscnt(N / 3) + 1;
        if (tmp < dp[N]) dp[N] = tmp;
    }
    if (N % 2 == 0) {
        int tmp = iscnt(N / 2) + 1;
        if (tmp < dp[N]) dp[N] = tmp;
    }
    return dp[N];
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) dp[i] = 1000006;
    printf("%d", iscnt(N));
}