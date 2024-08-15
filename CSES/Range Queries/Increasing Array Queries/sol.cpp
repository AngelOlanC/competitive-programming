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
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  vector<ll> p(n + 1);
  FOR (i, 0, n) {
    cin >> a[i];
    p[i + 1] = p[i] + a[i];
  }
  a[n] = 1e9 + 5;
  vector<vector<pi>> Q(n);
  FOR (i, 0, q) {
    int l, r;
    cin >> l >> r;
    Q[l - 1].pb({r - 1, i});
  }
  vector<ll> ans(q);
  vector<pair<int, ll>> st;
  st.pb({n, 0});
  ROF (l, n, 0) {
    while (!st.empty() && a[st.back().first] <= a[l]) st.pop_back();
    ll cont = st.back().second + (ll)a[l] * (st.back().first - l);
    st.pb({l, cont});
    // cout << l << ' ' << cont << ENDL;
    for (auto &[r, j] : Q[l]) {
      int le = 0, ri = SZ(st) - 1;
      while (le < ri) {
        int mi = (le + ri) / 2;
        if (st[mi].first <= r) ri = mi;
        else le = mi + 1;
      }
      ans[j] = st.back().second - st[le].second + (ll)a[st[le].first] * (r - st[le].first + 1) - (p[r + 1] - p[l]);
    }
  }
  for (auto &x : ans) cout << x << ENDL;
  return 0;
}