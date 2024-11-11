#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vi> mat(105, vi(105));
    FOR (i, 0, n) {
      int w, h;
      cin >> w >> h;
      FOR (i, 1, w + 1) {
        FOR (j, 1, h + 1) {
          mat[i][j] = 1;
        }
      }
    }
    int ans = 0;
    FOR (i, 0, 105) {
      FOR (j, 0, 105) {
        if (!mat[i][j]) {
          continue;
        }
        if (!mat[i - 1][j]) {
          ++ans;
        }
        if (!mat[i + 1][j]) {
          ++ans;
        }
        if (!mat[i][j - 1]) {
          ++ans;
        }
        if (!mat[i][j + 1]) {
          ++ans;
        }
      }
    }
    cout << ans << ENDL;
  }

  return 0;
}