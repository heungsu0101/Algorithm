#include <iostream>

using namespace std;

int num[1000000];

void primeNumberSieve(int M, int N) {
    for (int i = 2; i <= N; i++) {
        num[i] = i;
    }

    for (int i = 2; i * i <= N; i++) {
        if (num[i] == 0) continue;
        for (int j = i * i; j <= N; j += i) {
            num[j] = 0;
        }
    }

    for (int i = M; i <= N; i++) {
        if (num[i] != 0) printf("%d\n", i);
    }
}

int main() {
    int M, N; scanf("%d %d", &M, &N);
    primeNumberSieve(M, N);
}