#include <iostream>

using namespace std;

long long dp[101] = {0, 1, 1, 1, };

long long P(int N) {
    if (N == 1 || N == 2 || N == 3) return 1;
    if (dp[N] != 0) return dp[N];
    return dp[N] = P(N - 2) + P(N - 3);
}

int main() {
    int T; scanf("%d", &T);

    while (T--) {
        int N; scanf("%d", &N);
        printf("%lld\n", P(N));
    }
}