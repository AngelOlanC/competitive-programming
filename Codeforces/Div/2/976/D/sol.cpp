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

struct DSU {
  vector<int> e;
  int comp = 0;
  void init(int n) { e = vi(n, -1); comp = n; }
  int get(int x) { return e[x]<0?x:e[x]=get(e[x]);}
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    comp--;
    return true;
  }
};

void solve(int test_case) {
  int n, m;
  cin >> n >> m;
  vector<vi> mx(11, vi(n));
  FOR (i, 0, m) {
    int a, d, k;
    cin >> a >> d >> k;
    --a;
    mx[d][a] = max(mx[d][a], k);
  }
  DSU dsu;
  dsu.init(n);
  FOR (i, 0, n) {
    FOR (j, 1, 11) if (mx[j][i]) {
      dsu.join(i, i + j);
      mx[j][i + j] = max(mx[j][i + j], mx[j][i] - 1);
    }
  }
  cout << dsu.comp << ENDL;
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