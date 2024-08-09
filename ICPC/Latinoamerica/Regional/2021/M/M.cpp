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

  int n;
  cin >> n;
  vector<ll> t(n), d(n);
  FOR (i, 0, n) cin >> t[i] >> d[i];
  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return d[i] < d[j]; });
  vector<ll> s(n);
  auto upd = [&] (int i) {
    s[p[i]] = t[p[i]];
    if(i) s[p[i]] += s[p[i - 1]];
  };
  FOR (i, 0, n) {
    FOR (j, max(i - 10, 0), n) {
      upd(j);
      if (d[p[j]] < s[p[j]]) {
        cout << '*' << ENDL;
        return 0;
      }
    }
    int min_id = i;
    ll min_delta = d[p[i]] - s[p[i]];
    for (int j = i + 1; j < n; ++j) {
      ll S = t[p[j]];
      if (i) S += s[p[j - 1]];
      if (t[p[j]] <= min_delta && S <= d[p[j]] && p[j] < p[min_id]) min_id = j;
      min_delta = min(min_delta, d[p[j]] - s[p[j]]);
    }
    while(min_id > i) swap(p[min_id], p[min_id - 1]), --min_id;
    upd(i);
  }
  FOR (i, 0, n) cout << p[i] + 1 << " \n"[i == n - 1];

  return 0;
}