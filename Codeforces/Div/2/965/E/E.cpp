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
  int n, x;
  cin >> n >> x;
  vi a(n);
  vector<ll> pf(n + 1);
  FOR (i, 0, n) {
    cin >> a[i];
    pf[i + 1] = pf[i] + a[i];
  }
  stack<int> st;
  vi lg(n);
  FOR (i, 0, n) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    lg[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  vi rg(n);
  ROF (i, n, 0) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    rg[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return a[i] > a[j]; });
  vi can(n);
  FOR (k, 0, n) {
    int i = p[k], l = lg[i] + 1, r = rg[i] - 1;
    ll s = pf[r + 1] - pf[l];
    if (l == 0 && r == n - 1) {
      can[i] = 1;
      continue;
    }
    // cout << i << ' ' << l << ' ' << r << ' ' << s << ' ' << ENDL;
    if (l != 0 && s >= a[l - 1] && can[l - 1]) can[i] = 1;
    if (r != n - 1 && s >= a[r + 1] && can[r + 1]) can[i] = 1;
  }
  int ans = 0;
  FOR (i, 0, n) ans += can[i];
  cout << ans << ENDL;
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