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
  int diff = 0;
  vector<vi> occ(n);
  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
    --a[i];
    diff += occ[a[i]].empty();
    occ[a[i]].pb(i);
  }
  int ptr = 0;
  set<pair<int, int>> stmn, stmx;
  while (ptr < n) {
    stmn.insert({a[ptr], ptr});
    stmx.insert({-a[ptr], ptr});
    if (ptr == occ[a[ptr]].back()) break;
    ++ptr;
  }
  cout << diff << ENDL;
  int lst = 0;
  vi valid(n, 1);
  FOR (i, 0, diff) {
    auto [x, k] = i & 1 ? *stmn.begin() : *stmx.begin();
    if (x < 0) x = -x;
    cout << x + 1 << " \n"[i == diff - 1];
    valid[x] = 0;
    while (lst != k) {
      stmn.erase({a[lst], lst});
      stmx.erase({-a[lst], lst});
      lst++;
    }
    lst++;
    while (!stmn.empty() && !valid[stmn.begin()->first]) stmn.erase(stmn.begin());
    while (!stmx.empty() && !valid[-stmx.begin()->first]) stmx.erase(stmx.begin());
    if (ptr == k) ++ptr;
    while (ptr < n) {
      if (valid[a[ptr]]) stmn.insert({a[ptr], ptr}), stmx.insert({-a[ptr], ptr});
      if (valid[a[ptr]] && ptr == occ[a[ptr]].back()) break;
      ++ptr;
    }
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