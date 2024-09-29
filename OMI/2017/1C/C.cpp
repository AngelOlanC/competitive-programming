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

  int n, m;
  cin >> n >> m;

  vector<pi> e(m * 2);
  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    e[i] = {u, v}, e[i + m] = {v, u};
  }

  sort(ALL(e));

  int ptrb = 0, ptrf = 0, ans = 0, l = 0, cnt = 0, tam = 0;
  for (int r = 0; r < n; r++) {
    tam += r - l;
    while (ptrf < 2 * m && e[ptrf].first != r) ptrf++;
    while (ptrf < 2 * m && e[ptrf].first == r) cnt += e[ptrf].second >= l && e[ptrf].second < r, ptrf++;
    while (cnt != tam) {
      while (ptrb < 2 * m && e[ptrb].first != l) ptrb++;
      while (ptrb < 2 * m && e[ptrb].first == l) cnt -= e[ptrb].second > l && e[ptrb].second <= r, ptrb++;
      tam -= r - l;
      ++l;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << ENDL;

  return 0;
}