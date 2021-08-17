#include <iostream>
#include <vector>

using namespace std;

int num[10000];


void primeNumberSieve(int N) {
    for (int i = 2; i <= N; i++) {
        num[i] = i;
    }

    for (int i = 2; i * i <= N; i++) {
        if (num[i] == 0) continue;
        for (int j = i * i; j <= N; j += i) {
            num[j] = 0;
        }
    }
}

int main() {
    vector<int> ary;
    int T; scanf("%d", &T);

    while (T--) {
        int sum[2] = {0, 10000};
        int cnt = 10000;
        int n; scanf("%d", &n);
        primeNumberSieve(n);
        for (int i = 2; i <= n / 2; i++) {
            if (num[i] == 0) continue;
            if (num[n - i] == 0) continue;
            if (cnt > num[n - i] - num[i]) {
                cnt = num[n - i] - num[i];
                sum[0] = num[i];
                sum[1] = num[n - i];
            }
        }      
        for (int i = 0; i < 2; i++){
            ary.push_back(sum[i]);
        }   
    }
    for (int i = 0; i < ary.size(); i++){
        printf("%d ", ary[i]);
        if (i % 2 != 0) printf("\n");
    }       
}