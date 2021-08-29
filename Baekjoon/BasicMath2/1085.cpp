#include <iostream>

using namespace std;

int main() {
    int x, y, w, h; scanf("%d %d %d %d", &x, &y, &w, &h);
    int tmpx = 0, tmpy = 0;
    if (x > w / 2) tmpx = w - x;
    else tmpx = x;
    if (y > h / 2) tmpy = h - y;
    else tmpy = y;

    if (tmpx > tmpy) printf("%d", tmpy);
    else printf("%d", tmpx);
}