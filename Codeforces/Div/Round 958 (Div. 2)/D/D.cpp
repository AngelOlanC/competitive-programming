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

constexpr ll INF = LLONG_MAX;
constexpr int maxn = 3e5 + 5;

vector<vi> g;
vector<ll> a;
ll memo[maxn][2][2];

ll dp(int u, int pt, int ptt, int p = -1) {
  ll &ans = memo[u][pt][ptt];
  if (ans != INF) return ans;
  ll opt1 = a[u];
  if (u && !pt && !ptt) opt1 += a[u];
  for (auto &v : g[u]) if (v != p) opt1 += dp(v, 0, u && !pt && !ptt, u);
  ll opt2 = a[u] * 2ll;
  for (auto &v : g[u]) if (v != p) opt2 += dp(v, 0, 1, u);
  if (pt) return ans = min(opt1, opt2);
  ll opt3 = 0; 
  for (auto &v : g[u]) if (v != p) opt3 += dp(v, 1, 0, u);
  return ans = min({opt1, opt2, opt3});
}

void solve(int test_case) {
  int n;
  cin >> n;
  a.resize(n);
  for (auto &ai : a) cin >> ai;
  g.assign(n, vi());
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v);
    g[v].pb(u);
  }
  FOR (i, 0, n) FOR (j, 0, 2) FOR (k, 0, 2) memo[i][j][k] = INF;
  cout << accumulate(ALL(a), 0LL) + dp(0, 0, 0) << ENDL;
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