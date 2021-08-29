#include <iostream>
#include <vector>

using namespace std;

int dp[41] = {0, 1, };

int fibonacci(int n) {
    if (n == 0) return 0; 
    if (n == 1) return 1;
    if (dp[n] != 0) return dp[n];
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    vector<int> v;
    int T; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
        fibonacci(tmp);
    }

    for (int i = 0; i < v.size(); i++) {
        int tmp = v[i];
        if (tmp == 0) printf("1 0\n");
        else if (tmp == 1) printf("0 1\n");
        else if (tmp == 2) printf("1 1\n"); 
        else printf("%d %d\n", dp[tmp - 3] + dp[tmp - 2], dp[tmp - 2] + dp[tmp - 1]);
    }
}