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

const int N = 5e5 + 50;
int vis[N];

void init() {
  for (int k = 2; k < N; k++) {
    //enum num of 1
    LL cur = 1;
   // cout << k << endl;
    for (; cur < N; cur = cur * k + 1) {
      if (!vis[cur]) vis[cur] = k;
    }
  }
}

int main() {
#ifdef JUDGE
    freopen("G:\\C\\AC\\medium\\data\\in5.txt", "r", stdin);
    freopen("G:\\C\\AC\\medium\\data\\out5.txt", "w", stdout);
#endif
    init();
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        cout << vis[x] << endl;
    }
  return 0;
}
