#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;

    vector<int> ary;

    for (int i = 0; i < N; i++) {
        int check = 0;
        int ipt; cin >> ipt;
        ary.push_back(ipt);

        if (ary[i] == 1) {
            continue;
        }

        for (int j = 2; j < ary[i]; j++) {
            if (ary[i] % j) {
                continue;
            }
            check = 1;   
        }

        if (check == 0) {
            cnt++;
        }
    }

    cout << cnt;
}