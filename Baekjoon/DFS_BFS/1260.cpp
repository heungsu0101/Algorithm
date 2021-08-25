#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> ary[1003];
queue<int> q;

bool check[1003];

void dfs(int num) {
    if (check[num] == true) return;
    printf("%d ", num);
    check[num] = true;

    for (int i = 0; i < ary[num].size(); i++) {
        if (check[ary[num][i]] == true) continue;
        else {
            dfs(ary[num][i]);
        }
    }

    return;          
}

void bfs(int num) {
    q.push(num);
    check[num] = true;
    while (!q.empty())
    {   
        int cur = q.front();
        printf("%d ", cur);
        q.pop();
        for (int i = 0; i < ary[cur].size(); i++) {
            if (check[ary[cur][i]] == false) {
                check[ary[cur][i]] = true;
                q.push(ary[cur][i]);
            }
        } 
    }

    return;
}

int main() {
    int N, M, V; scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        int n1, n2; scanf("%d %d", &n1, &n2);
        ary[n1].push_back(n2);
        ary[n2].push_back(n1);
    }

    // 배열 정렬 
    for (int i = 1; i <= N; i++) {
        sort(ary[i].begin(), ary[i].end());
    }   

    dfs(V);
    printf("\n");

    for (int i = 1; i <= N; i++) {
        check[i] = false;
    }

    bfs(V);
}