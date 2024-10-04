#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
    string s;
    cin >> s;
    int n = SZ(s);
    vector<vi> lcp(n, vi(n + 1));
    FOR (len, 1, n) ROF (i, n - len, 0) lcp[i][i + len] = 1 + lcp[i + 1][i + len + 1];
    vector<vi> pc(n, vi(n)), pl(n, vi(n));  
    FOR (i, 0, n) {
      FOR (len, 1, i + 1) if (lcp[i - len][i] == len) {
        pc[i][len] = 1;
        pl[i][len] = len;
      }
      FOR (len, 1, n) {
        pc[i][len] += pc[i][len - 1]; 
        pl[i][len] += pl[i][len - 1];
      }
    }
    ll ans = 0;
    FOR (i, 0, n) FOR (j, i + 2, n) if (lcp[i][j] >= 2) {
      int x = min(j - i - 2, lcp[i][j] - 1);
      ans += (ll)(x + 1) * pc[i][x] - pl[i][x];
    }
    cout << ans << ENDL;
  }

  return 0;
}