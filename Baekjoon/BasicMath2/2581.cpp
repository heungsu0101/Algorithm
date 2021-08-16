#include <iostream>

using namespace std;

int main() {
    int N, M, sum = 0, min = 10001;
    cin >> M >> N;

    while (M <= N) {
        int check = 1; //1이면 소수

        if (M == 1) {
                check = 0;
        }

        for (int i = 2; i < M; i++) {
            if ((M % i) == 0) {
                check = 0;
                break;
            }
        }

        if (check == 1) {
            if (min > M) {
                min = M;
            }

            sum += M;
        }

        M++;
    }
    
    if (sum == 0) {
        cout << -1;
        return 0;
    }

    cout << sum << "\n" << min;

}