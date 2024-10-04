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

pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
  int res = 0;
  vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
    }
    return 0;
  };
  while (1) {
    fill(ALL(A), 0);
    fill(ALL(B), 0);
    /// Encuentra los nodos restantes para BFS (i.e. con layer 0)
    cur.clear();
    for (int a : btoa) if(a != -1) A[a] = -1;
    FOR (a, 0, SZ(g)) if(A[a] == 0) cur.pb(a);
    /// Encunetra todas las layers usando BFS
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur) for (int b : g[a]) {
        if (btoa[b] == -1) {
          B[b] = lay;
          islast = 1;
        }
        else if (btoa[b] != a && !B[b]) {
          B[b] = lay;
          next.pb(btoa[b]);
        }
      }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    /// Usa DFS para escanear caminos aumentantes
    FOR (a, 0, SZ(g)) res += dfs(dfs, a, 0);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, e;
  cin >> n >> e;
  vector<string> enemies(e);
  map<string, int> enemies_id;
  FOR (i, 0, e) {
    cin >> enemies[i];
    enemies_id[enemies[i]] = i;
  }
  vector<string> allies(n);
  vi energy(n);
  vector<vi> g(n);
  FOR (i, 0, n) {
    int k;
    cin >> allies[i] >> energy[i] >> k;
    while (k--) {
      string enemy;
      cin >> enemy;
      g[i].pb(enemies_id[enemy]);
    }
  }
  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) -> bool { return allies[i] < allies[j]; });
  int ans_matchings = -1, ans_msk, ans_sum = 0;
  FOR (msk, 0, (1<<n)) if (__builtin_popcount(msk) == e) {
    vector<vi> g2(e);
    int sum = 0;
    FOR (i, 0, n) if ((msk >> i) & 1) {
      sum += energy[p[i]];
      g2.pb(g[p[i]]);
    }
    int matchings = hopcroftKarp(g2, e).first;
    if (matchings < ans_matchings) continue;
    if (matchings > ans_matchings) {
      ans_matchings = matchings;
      ans_sum = sum;
      ans_msk = msk;
      continue;
    }
    if (sum < ans_sum) continue;
    if (sum > ans_sum) {
      ans_sum = sum;
      ans_msk = msk;
      continue;
    }
    FOR (i, 0, n) {
      bool bit_ans = (ans_msk >> i) & 1, bit_curr = (msk >> i) & 1;
      if (bit_ans && !bit_curr) break;
      if (!bit_ans && bit_curr) {
        ans_msk = msk;
        break;
      }
    }
  }
  FOR (i, 0, n) if ((ans_msk >> i) & 1) cout << allies[p[i]] << ENDL;
  return 0;
}