#include <iostream>

using namespace std;

void primeNumberSieve(int ary[], int N) {
    for (int i = 2; i <= N; i++) {
        ary[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        if (ary[i] == 0 ) continue;
        for (int j = i + i; j <= N; j += i) {
            ary[j] = 0;
        }
    }
}

int main() {
    int num[10001] = {0};
    int sum = 0, min = 10001;
    int N, M; cin >> M >> N;

    primeNumberSieve(num, N);
    for (int i = M; i <= N; i++) {
        if (num[i] == 0) continue;
        if (min > num[i]) min = num[i];
        sum += num[i]; 
    }

    if (sum == 0) cout << -1;
    else cout << sum << "\n" << min;
}