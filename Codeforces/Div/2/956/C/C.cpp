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

  vector<vector<ll>> a(3, vector<ll>(n));
  FOR (i, 0, 3) {
    for (auto &x : a[i]) {
      cin >> x;
    }
  }

  vector<vector<ll>> p(3, vector<ll>(n + 1, 0));
  FOR (i, 0, 3) {
    FOR (j, 1, n + 1) {
      p[i][j] = p[i][j - 1] + a[i][j - 1];
    }
  }

  ll mn = 0;
  FOR (i, 0, n) {
    mn += a[0][i];
  }

  mn = (mn + 3 - 1) / 3;

  vector<array<int, 3>> triplets;
  FOR (a, 0, 3) {
    FOR (b, 0, 3) if (a != b) {
      FOR (c, 0, 3) if (a != c && b != c) {
        triplets.pb({a, b, c});
      }
    }
  }

  FOR (i, 2, n) {
    for (auto &[a, b, c] : triplets) {
      if (p[a][i - 1] < mn) continue;
      auto j = lower_bound(ALL(p[b]), p[b][i - 1] + mn) - p[b].begin();
      if (j > n || p[c][n] - p[c][j] < mn) continue;
      vector<pi> ans(3);
      ans[a] = {1, i - 1};
      ans[b] = {i, j};
      ans[c] = {j + 1, n};
      for (auto &[l, r] : ans) {
        cout << l << ' ' << r << ' ';
      }
      cout << ENDL;
      return;
    }
  }
  cout << -1 << ENDL;
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