#include <iostream>

using namespace std;

int main() {
    while (1) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;

        a *= a; b*= b; c *= c; 
        if (a <= b && c <= b) {
            if (a + c == b) printf("right\n");
            else printf("wrong\n");
        }
        else if (b <= a && c <= a) {
            if (b + c == a) printf("right\n");
            else printf("wrong\n");
        }
        else {
            if (a + b == c) printf("right\n");
            else printf("wrong\n");
        }
    }
}