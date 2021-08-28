#include <iostream>
#include <queue>

using namespace std;

int box[1003][1003];
int check[1003][1003];

int dx[4] = {1, -1, 0, 0}; // 동서남북
int dy[4] = {0, 0, -1, 1};

struct xy {
    int x;
    int y;
};

queue<xy> q;

bool end(int M, int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (box[i][j] != 0) continue;
            return false;
        }
    }
    return true;
}

void isTime(int M, int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (box[i][j] == 1) {
                q.push({j, i});
            }
        }
    }

    while (!q.empty()) {
        int xcur = q.front().x;
        int ycur = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xcur + dx[i];
            int ny = ycur + dy[i];
            // 익은 토마트, 비어있는 곳 패스
            if (box[ny][nx] != 0) continue;
            // 박스를 나갔을 때
            if (1 > ny || ny > N || 1 > nx || nx > M) continue;
            box[ny][nx] = 1;
            check[ny][nx] = check[ycur][xcur] + 1;
            q.push({nx, ny});
        }
    }

    if (end(M, N)) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (check[i][j] > cnt) cnt = check[i][j];     
            }
        }
        printf("%d", cnt);  
    } else {
        printf("-1");
    }
}

int main() {
    int M, N; scanf("%d %d", &M, &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &box[i][j]);
        }
    }
    isTime(M, N);
}