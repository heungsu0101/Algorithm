#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int cnt[100005];
bool check[100005];
int bfs(int N, int K) {
    check[N] = true;
    q.push(N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == K) return cnt[cur];
        if (cur - 1 >= 0 && check[cur - 1] == false) {
            cnt[cur - 1] = cnt[cur] + 1;
            check[cur - 1] = true;
            q.push(cur - 1);
        }
        if (cur + 1 <= 100000 && check[cur + 1] == false) {
            cnt[cur + 1] = cnt[cur] + 1;
            check[cur + 1] = true;
            q.push(cur + 1);
        }
        if (cur * 2 <= 100000 && check[cur * 2] == false) {            
            cnt[cur * 2] = cnt[cur] + 1;
            check[cur * 2] = true;
            q.push(cur * 2); 
        }
    }

    return 0;
}

int main() {
    int N, K; scanf("%d %d", &N, &K);
    printf("%d", bfs(N, K));
    
}