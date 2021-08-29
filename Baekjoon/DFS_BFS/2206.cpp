#include <iostream>
#include <queue>

using namespace std;

struct xy {
    int x;
    int y;
    int wall;
};

int maze[1003][1003];
int check[1003][1003][2];

int dx[4] = {-1, 1, 0 ,0}; // 동서남북
int dy[4] = {0, 0, -1, 1};
queue<xy> q;

int bfs(int N, int M) {
    q.push({1, 1, 0});
    check[1][1][0] = 1;
    while (!q.empty()) {
        int xcur = q.front().x;
        int ycur = q.front().y;
        int wall = q.front().wall;
        q.pop();

        // 목적지 도착했을 때
        if (xcur == M && ycur == N) return check[ycur][xcur][wall];

        for (int i = 0; i < 4; i++) {
            int nx = xcur + dx[i];
            int ny = ycur + dy[i];

            // 미로 범위를 벗어났을 때
            if (1 > nx || nx > M || 1 > ny || ny > N) continue;
            // 벽일 때 + 뚫을 수 있을 때
            if (maze[ny][nx] == 1 && wall == 0) {
                if (check[ny][nx][wall + 1] > check[ycur][xcur][wall] + 1) {
                    check[ny][nx][wall + 1] = check[ycur][xcur][wall] + 1;
                    q.push({nx, ny, wall + 1});
                }
            }
            // 길일 때
            if (maze[ny][nx] == 0) {
                if (check[ny][nx][wall] > check[ycur][xcur][wall] + 1) {
                    check[ny][nx][wall] = check[ycur][xcur][wall] + 1;
                    q.push({nx, ny, wall});
                }
            }
        }
    }

    return -1;
}

int main() {
    int N, M; scanf("%d %d", &N, &M); 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
            check[i][j][0] = 10000007;
            check[i][j][1] = 10000007;
        }
    }
    printf("%d\n", bfs(N, M));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%d ", check[i][j][1]);
        }
        printf("\n");
    }
}