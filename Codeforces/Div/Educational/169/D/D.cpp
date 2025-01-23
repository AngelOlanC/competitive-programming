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
  
  vector<vi> diff(6, vi(6));
  diff[0][5] = diff[5][0] = 1;
  diff[1][4] = diff[4][1] = 1;
  diff[2][3] = diff[3][2] = 1;

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    int n, q;
    cin >> n >> q;
    vi a(n);
    FOR (i, 0, n) {
      string s;
      cin >> s;
      if (s == "BG") a[i] = 0;
      if (s == "BR") a[i] = 1;
      if (s == "BY") a[i] = 2;
      if (s == "GR") a[i] = 3;
      if (s == "GY") a[i] = 4;
      if (s == "RY") a[i] = 5;
    }
    vi lst(6, -1);
    vector<vi> le(n, vi(6));
    FOR (i, 0, n) {
      FOR (j, 0, 6) le[i][j] = lst[j];
      lst[a[i]] = i;
    }
    lst.assign(6, -1);
    vector<vi> ri(n, vi(6));
    ROF (i, n, 0) {
      FOR (j, 0, 6) ri[i][j] = lst[j];
      lst[a[i]] = i;
    }
    while (q--) {
      int i, j;
      cin >> i >> j;
      --i, --j;
      if (!diff[a[i]][a[j]]) {
        cout << abs(i - j) << ENDL;
        continue;
      }
      if (i > j) swap(i, j);
      int ans = 1e9;
      FOR (k, 0, 6) if (k != a[i] && k != a[j] && ri[i][k] != -1) { // der
        ans = min(ans, ri[i][k] - i + abs(j - ri[i][k]));
      }
      FOR (k, 0, 6) if (k != a[i] && k != a[j] && le[i][k] != -1) { // izq
        ans = min(ans, i - le[i][k] + j - le[i][k]);
      }
      if (ans == 1e9) ans = -1;
      cout << ans << ENDL;
    }
  }

  return 0;
}