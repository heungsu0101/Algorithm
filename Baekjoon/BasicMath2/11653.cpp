#include <iostream>

using namespace std;

int num[10000000];
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
    int N; scanf("%d", &N);
    
    primeNumberSieve(N);

    int i = 2;
    while (N != 1) {
        if (num[i] != 0) {
            while (N % num[i] == 0) {
                N /= num[i];
                printf("%d\n", num[i]);

                if (N == 1) break;
            }    
        }
        i++;
    }
}