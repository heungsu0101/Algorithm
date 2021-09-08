#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[100006];
vector<int> v;

int binarySearch(int target, int start, int end) {
    if (start > end) return 0;

    int mid = (start + end) / 2;
    if (A[mid] == target) return 1;
    else if (A[mid] > target) return binarySearch(target, start, mid - 1);
    else return binarySearch(target, mid + 1, end);
}

int main() {
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A + N);

    int M; scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
    }
    
    for (int i = 0; i < M; i++) {
        printf("%d\n", binarySearch(v[i], 0, N));
    }
}