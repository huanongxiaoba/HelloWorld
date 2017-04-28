/*zhen hao*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

#define lson l, m, rt*2
#define rson m + 1, r, rt*2+1
#define xx first
#define yy second

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int N = 1e5 + 10, mod = 1e9 + 7;
char s[N];
int pos[30];
LL dp[N], sum[N];

LL solve() {
    int n = strlen(s);
    memset(pos, -1, sizeof pos);
    for (int i = 1; i <= n; i++) {
        int c = s[i - 1] - 'a';
        if (pos[c] == -1) {
            dp[i] = (sum[i - 1] + 1) % mod;
        }
        else {
            dp[i] = (sum[i - 1] - sum[pos[c] - 1]) % mod;
        }
        sum[i] = (sum[i - 1] + dp[i]) % mod;
        pos[c] = i;
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        (res += dp[i]) %= mod;
    }
    return (res + mod) % mod;
}

LL check() {
    int n = strlen(s);
    set<string> S;
    for (int i = 1; i < 1 << n; i++) {
        string str;
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            str = str + s[j];
        }
        S.insert(str);
    }
    return S.size();
}

int main() {
#ifdef JUDGE
    freopen("G:\\C\\AC\\hard\\data\\in2.txt", "r", stdin);
    freopen("G:\\C\\AC\\hard\\data\\out2.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        scanf("%s", s);
//        cout << check();
        cout << solve() << '\n';
    }
    return 0;
}
