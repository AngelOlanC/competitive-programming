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
  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR (i, 1, n) {
    cin >> a[i];
    --a[i];
  }
  vi sz(n, 1);
  ROF (i, n, 1) sz[a[i]] += sz[i];
  vector<set<int>> ch(n);
  vi p(n), rp(n);
  FOR (i, 0, n) {
    cin >> p[i];
    rp[--p[i]] = i;
    ch[a[p[i]]].insert(i);
  }
  ch[0].erase(rp[0]);
  auto check = [&](int u) -> int {
    return sz[u] == 1 || (rp[u] < *ch[u].begin() && *--ch[u].end() + sz[p[*--ch[u].end()]] <= rp[u] + sz[u]); 
  };
  int cnt = 0;
  FOR (i, 0, n) cnt += check(i);
  while (q--) {
    int i, j;
    cin >> i >> j;
    int u = p[--i], v = p[--j];
    set<int> s{u, v, a[u], a[v]};
    for (auto &x : s) cnt -= check(x);
    swap(p[i], p[j]), swap(rp[u], rp[v]);
    ch[a[u]].erase(i), ch[a[v]].erase(j), ch[a[u]].insert(j), ch[a[v]].insert(i);
    if (!u) ch[0].erase(j);
    if (!v) ch[0].erase(i);
    for (auto &x : s) cnt += check(x);
    cout << (cnt == n ? "YES" : "NO") << ENDL;
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