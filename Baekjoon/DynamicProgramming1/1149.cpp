#include <iostream>
#include <algorithm>

using namespace std;

int ary[1003][3];
int dp[1003][3];

int isPrice(int N, int color) {
    if (dp[N][color] != 0) return dp[N][color];
    if (color == 0) {
        return dp[N][color] = ary[N][color] + min(isPrice(N - 1, 1), isPrice(N - 1, 2));
    } else if (color == 1) {
        return dp[N][color] = ary[N][color] + min(isPrice(N - 1, 0), isPrice(N - 1, 2));          
    } else {
        return dp[N][color] = ary[N][color] + min(isPrice(N - 1, 0), isPrice(N - 1, 1));
    }
}

int main() {
    int N; scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &ary[i][j]); 
        }
    }

    dp[1][0] = ary[1][0];
    dp[1][1] = ary[1][1];
    dp[1][2] = ary[1][2];

    isPrice(N, 0); isPrice(N, 1); isPrice(N, 2);
    int tmp = 1000006;
    for (int i = 0; i < 3; i++) {
        if (tmp > dp[N][i]) tmp = dp[N][i];
    }
    printf("%d\n", tmp);
}