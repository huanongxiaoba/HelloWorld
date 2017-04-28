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
    freopen("G:\\C\\AC\\medium\\data\\in4.txt", "w", stdout);
#endif
    srand((unsigned)time(0));
    int T = 10000;
    cout << T << '\n';
    for (int i = 1; i <= T; i++) {
        printf("%d\n", get_random(400000, 500000));
    }
    return 0;
}
