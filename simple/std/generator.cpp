/*zhen hao*/
#include <bits/stdc++.h>
using namespace std;

#define lson l, m, rt*2
#define rson m + 1, r, rt*2+1
#define xx first
#define yy second

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

int get_random(int l, int r) {
    return rand() % (r - l) + l;
}

int main() {
#ifdef JUDGE
//    freopen("case.in", "r", stdin);
    freopen("G:\\C\\AC\\simple\\in3.txt", "w", stdout);
#endif
    srand((unsigned)time(0));
    int T = 20;
    cout << T << '\n';
    for (int i = 1; i <= T; i++) {
        int n = i * 5;
        int m = (T + 1 - i) * 5;
        cout << n << ' ' << m << '\n';
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++)  putchar(get_random(0, 2) ? '*' : '.');
            puts("");
        }
    }
    return 0;
}
