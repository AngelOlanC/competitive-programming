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
  vector<pi> ans;
  vector<set<int>> g(n + 1);
  FOR (i, 2, n + 1) g[1].insert(i);
  auto dfs = [&](auto &&dfs, int u) -> void {
    vi child;
    for (auto &v : g[u]) {
      cout << "? " << u << ' ' << v << endl;
      int mid;
      cin >> mid;
      assert(mid != -1);
      if (mid == u) {
        ans.pb({u, v});
        child.pb(v);
      }
      else g[mid].insert(v);
    }
    for (auto &v : child) {
      dfs(dfs, v);
    }
  };
  dfs(dfs, 1);
  cout << "! ";
  for (auto &[u, v] : ans) {
    cout << u << ' ' << v << ' ';
  }
  cout << endl;
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