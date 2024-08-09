#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
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

constexpr int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
constexpr int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int n, k;
int occupied[26][26];

int color(int x, int y) {
  return (x + y) % 2;
}

int encode(int x, int y) {
  return x * n + y;
}

int valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> k;

  vector<vi> g(n * n);
  while (k--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    occupied[x][y] = 1;

    int c = color(x, y), i = encode(x, y);
    FOR (k, 0, 8) {
      int xx = x + dx[k], yy = y + dy[k];
      if (!valid(xx, yy) || !occupied[xx][yy]) {
        continue;
      }
      int ii = encode(xx, yy);
      if (c) {
        g[ii].pb(i);
      } else {
        g[i].pb(ii);
      }
    }
  }
  cout << hopcroftKarp(g, n * n).first << ENDL;

  return 0;
}