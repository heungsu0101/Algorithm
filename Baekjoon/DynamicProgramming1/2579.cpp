#include <iostream>
#include <algorithm>

using namespace std;

int stair[301];
int dp[301];

int isScore(int N) {
    if (N < 1) return 0;
    if (dp[N] != 0) return dp[N];
    return dp[N] = stair[N] + max(stair[N - 1] + isScore(N - 3), isScore(N - 2));
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &stair[i]);
    }
    printf("%d\n", isScore(N));
}