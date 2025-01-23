#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vector<int>>& g, int m) {
	int res = 0;
  vector<int> btoa(m, -1);
	vector<int> A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(A.begin(), A.end(), 0);
		fill(B.begin(), B.end(), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		for (int a = 0; a < (int)g.size(); ++a) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
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
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		for (int a = 0; a < (int)g.size(); ++a)
      res += dfs(a, 0, g, btoa, A, B);
	}
}

void find_cliques(int u, int c, vector<vector<int>>& g, vector<vector<int>>& cliques, vector<int>& cnt_cliques) {
  int in_clique = u;
  cliques[c][u] = cnt_cliques[c]++;
  for (int v = 0; v < (int)g.size(); ++v) {
    if (g[u][v] && g[v][in_clique] && (cliques[c ^ 1][u] == -1 || cliques[c ^ 1][u] != cliques[c ^ 1][v])) {
      cliques[c][v] = cliques[c][u];
      in_clique = v;
    }
  }
  if (cliques[c ^ 1][u] == -1) {
    find_cliques(u, c ^ 1, g, cliques, cnt_cliques);
  }
  for (int v = 0; v < (int)g.size(); ++v) {
    if (g[u][v] && cliques[c ^ 1][v] == -1) {
      find_cliques(v, c ^ 1, g, cliques, cnt_cliques);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      g[i][j] = c == '1';
    }
  }

  vector<vector<int>> cliques(2, vector<int>(n, -1));
  vector<int> cnt_cliques(2);
  for (int i = 0; i < n; ++i) {
    if (cliques[0][i] == -1) {
      find_cliques(i, 0, g, cliques, cnt_cliques);
    }
  }

  vector<vector<int>> g_bip(cnt_cliques[0]);
  for (int i = 0; i < n; ++i) {
    g_bip[cliques[0][i]].push_back(cliques[1][i]);
  }
  cout << hopcroftKarp(g_bip, cnt_cliques[1]) << '\n';
  
  return 0;
}