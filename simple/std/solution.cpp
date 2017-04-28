/*zhen hao*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define lson l, m, rt*2
#define rson m + 1, r, rt*2+1
#define xx first
#define yy second

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> pii;

const int N = 110;
int len[N][N][4], n, m;
char s[N][N];

void init() {
  memset(len, 0, sizeof len);
  //up
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      len[i][j][0] = (s[i][j] == '.' ? len[i - 1][j][0] + 1 : 0);
  //down
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      len[i][j][1] = (s[i][j] == '.' ? len[i + 1][j][1] + 1 : 0);
  //left
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      len[i][j][2] = (s[i][j] == '.' ? len[i][j - 1][2] + 1 : 0);
  //right
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      len[i][j][3] = (s[i][j] == '.' ? len[i][j + 1][3] + 1 : 0);
}

int main() {
#ifdef JUDGE
    freopen("G:\\C\\AC\\simple\\in5.txt", "r", stdin);
    freopen("G:\\C\\AC\\simple\\out5.txt", "w", stdout);
#endif
  int tcase;
  cin >> tcase;
  while (tcase--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    init();
    int S = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) if (s[i][j] == '.') {
        //s
        for (int l = 2; l < len[i][j][2]; l++) {
          int x = i, y = j;
          y = y - l;
          if (len[x][y][1] <= l) continue;
          x = x + l;
          if (len[x][y][3] <= l) continue;
          y = y + l;
          if (len[x][y][1] <= l) continue;
          x = x + l;
          if (len[x][y][2] <= l) continue;
          S++;
        }
      }
    cout << S << endl;
  }
  return 0;
}
