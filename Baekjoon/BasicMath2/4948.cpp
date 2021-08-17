#include <iostream>
#include <vector>

using namespace std;

int num[246912];

int primeNumberSieve(int N) {
    int cnt = 0;

    for (int i = 2; i <= 2 * N; i++) {
        num[i] = i;
    }

    for (int i = 2; i * i <= 2 * N; i++) {
        if (num[i] == 0) continue;
        for (int j = i * i; j <= 2 * N; j += i ) {
            num[j] = 0;
        }
    }

    for (int i = N + 1; i <= 2 * N; i++) {
        if (num[i] != 0) cnt++;
    }
    
    return cnt;
}

int main() {
    vector<int> check;
    int N; scanf("%d", &N);

    while (N != 0) {
        check.push_back(primeNumberSieve(N));
        scanf("%d", &N);
    }

    int size = check.size();
    for (int i = 0; i < size; i++) {
        printf("%d\n", check[i]);
    }
}