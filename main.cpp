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

const int N = 80;
int dp[N][N][N][3];
//0 X
//1 K
//2 V

int cntX[N], cntK[N], cntV[N], posX[N], posK[N], posV[N];

inline int myabs(int x) { return x > 0 ? x : 0; }

int main() {
#ifdef JUDGE
    freopen("case.in", "r", stdin);
#endif
    int n;
    string s;
    cin >> n >> s;

    memset(posX, -1, sizeof posX);
    memset(posK, -1, sizeof posK);
    memset(posV, -1, sizeof posV);
    int X = 0, V = 0, K = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'K') K++, posK[K] = i;
        else if (s[i] == 'V') V++, posV[V] = i;
        else X++, posX[X] = i;
        cntX[i] = X;
        cntK[i] = K;
        cntV[i] = V;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0][0] = 0;
    for (int i = 0; i <= X; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= V; k++) {
                for (int l = 0; l < 3; l++) {
                    int pos, weight;
                    pos = posX[i + 1];
                    if (pos != -1) {
                        weight = myabs(cntK[pos] - j) + myabs(cntV[pos] - k);
                        dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][l] + weight);
                    }
                    pos = posK[j + 1];
                    if (pos != -1 && l != 2) {
                        weight = myabs(cntX[pos] - i) + myabs(cntV[pos] - k);
                        dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][l] + weight);
                    }
                    pos = posV[k + 1];
                    if (pos != -1) {
                        weight = myabs(cntX[pos] - i) + myabs(cntK[pos] - j);
                        dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2], dp[i][j][k][l] + weight);
                    }
                }
            }
        }
    }
    int res = 1<<30;
    for (int i = 0; i < 3; i++) res = min(res, dp[X][K][V][i]);
    cout << res << endl;
    return 0;
}
