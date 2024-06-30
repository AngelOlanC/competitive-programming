#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int t) {
  int n, k, q;
  cin >> n >> k >> q;

  vector<pi> v;
  v.pb({0, 0});

  vi a(k), b(k);
  for (auto &ai : a) {
    cin >> ai;
  }
  for (auto &bi : b) {
    cin >> bi;
  }

  FOR (i, 0, k) {
    v.push_back({a[i], b[i]});
  }

  while (q--) {
    int x;
    cin >> x;

    if (x == n) {
      cout << v.back().second << ' ';
      continue;
    }

    auto it = upper_bound(ALL(v), make_pair(x, 0));
    it--;

    auto [x1, t1] = *it;

    it++;
    auto [x2, t2] = *it;

    ll ans = t1 + 1ll * (x - x1) * (t2 - t1) / (x2 - x1);
    cout << ans << ' ';
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}