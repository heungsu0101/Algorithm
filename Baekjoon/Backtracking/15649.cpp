#include <iostream>

using namespace std;

bool num[9];
int order[9];

void permutation(int k, int N, int M) {
    
    if (k == M + 1) {
        for (int i = 1; i <= M; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= N; i++) {
            if (num[i] == true) continue;
            else {
                order[k] = i;
                num[i] = true;
                permutation(k + 1, N, M);
                num[i] = false;
            }
        }
    }
}

int main() {
    int N, M; scanf("%d %d", &N, &M);

    permutation(1, N, M);
}