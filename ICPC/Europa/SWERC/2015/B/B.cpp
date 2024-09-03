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

struct TwoSat {
  int N;
  vector<vi> g;
  vi values;  // 0 = false, 1 = true

  TwoSat(int n = 0) : N(n), g(2 * n) {}

  int addVar() {
    g.emplace_back();
    g.emplace_back();
    return N++;
  }

  // Agregar una disyuncion
  void either(int x, int y) {  // Nota: (a v b), es equivalente a la expresion (~a -> b) n (~b -> a)
    x = max(2 * x, -1 - 2 * x), y = max(2 * y, -1 - 2 * y);
    g[x].push_back(y ^ 1), g[y].push_back(x ^ 1);
  }
  void setValue(int x) { either(x, x); }
  void implies(int x, int y) { either(~x, y); }
  void make_diff(int x, int y) {
    either(x, y);
    either(~x, ~y);
  }
  void make_eq(int x, int y) {
    either(~x, y);
    either(x, ~y);
  }

  void atMostOne(const vi& li) {
    if (li.size() <= 1) return;
    int cur = ~li[0];
    for (int i = 2; i < li.size(); i++) {
      int next = addVar();
      either(cur, ~li[i]);
      either(cur, next);
      either(~li[i], next);
      cur = ~next;
    }
    either(cur, ~li[1]);
  }

  vi dfs_num, comp;
  stack<int> st;
  int time = 0;
  int tarjan(int u) {
    int x, low = dfs_num[u] = ++time;
    st.push(u);
    for (int v : g[u])
      if (!comp[v])
        low = min(low, dfs_num[v] ?: tarjan(v));
    if (low == dfs_num[u]) {
      do {
        x = st.top();
        st.pop();
        comp[x] = low;
        if (values[x >> 1] == -1)
          values[x >> 1] = x & 1;
      } while (x != u);
    }
    return dfs_num[u] = low;
  }

  bool solve() {
    values.assign(N, -1);
    dfs_num.assign(2 * N, 0);
    comp.assign(2 * N, 0);
    for (int i = 0; i < 2 * N; i++) if (!comp[i]) tarjan(i);
    for (int i = 0; i < N; i++) if (comp[2 * i] == comp[2 * i + 1]) return 0;
    return 1;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pi> invalid;
  FOR (i, 0, 26) {
    invalid.pb({i, ~(i + 26)});
    invalid.pb({i + 26, ~i});
  }

  int n;
  cin >> n;
  vi fixed;
  vector<pi> at_least_one;
  while (n--) {
    char c1, c2;
    int p, k;
    cin >> c1 >> c2 >> p >> k;
    int x = c1 - 'A', y = c2 - 'A';
    if (p == 2) x += 26, y += 26;
    if (!k) {
      fixed.pb(~x);
      fixed.pb(~y);
      continue;
    }
    if (k == 1) {
      at_least_one.pb({x, y});
      continue;
    }
    fixed.pb(x);
    fixed.pb(y);
  }

  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = i + 1; j < 26; ++j) {
      for (int k = j + 1; k < 26; ++k) {
        TwoSat twoSat(52);
        for (auto &[x, y] : invalid) twoSat.implies(x, y);
        for (auto &x : fixed) twoSat.setValue(x);
        for (auto &[x, y] : at_least_one) twoSat.make_diff(x, y);
        for (int l = 0; l < 26; ++l) if (l != i && l != j && l != k) {
          twoSat.either(l, l + 26);
        }
        twoSat.setValue(~i), twoSat.setValue(~(i + 26));
        twoSat.setValue(~j), twoSat.setValue(~(j + 26));
        twoSat.setValue(~k), twoSat.setValue(~(k + 26));
        ans += twoSat.solve();
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}