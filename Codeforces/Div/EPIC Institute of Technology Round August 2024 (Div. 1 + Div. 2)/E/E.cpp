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

void solve(int test_case) {
  int n;
  cin >> n;
  vector<pi> a(n);
  for (auto &[c, x] : a) cin >> c >> x;
  vector<stack<pair<ll, ll>>> stx(n + 1);
  stack<pair<ll, pair<ll, int>>> stg;
  ll ans = 0;
  FOR (i, 0, n) {
    auto [c, x] = a[i];
    while (!stx[x].empty() && stx[x].top().first < c) stx[x].pop();
    if (stx[x].empty()) {
      ans = max(ans, (ll)c);
      stx[x].push({c, 0});
      while (!stg.empty() && stg.top().first < c) stg.pop();
      stg.push({c, {0, x}});
      continue;
    }
    if (stg.top().second.first != x && stg.top().first >= stx[x].top().first) {
      ans = max(ans, (ll)c);
      stx[x].push({c, 0});
      while (!stg.empty() && stg.top().first < c) stg.pop();
      stg.push({c, {0, x}});
      continue;
    }
    ll gre = 0;
    while (!stg.empty() && stg.top().second.first != x) {
      gre = max(gre, (ll)stg.top().second.second);
      stg.pop();
    }
    auto [ct, tt] = stx[x].top();
    stg.pop(); stx[x].pop();
    stg.push({ct + c - gre, {c - gre, x}});
    stx[x].push({ct + c - gre, c - gre});
    ans = max(ans, ct + c - gre);
    cout << ans << "  \n"[i == n - 1];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}