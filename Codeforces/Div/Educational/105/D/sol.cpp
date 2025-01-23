#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int f(vector<int>& leaves, vector<int>& c, vector<pair<int, int>>& e, vector<vector<int>>& a) {
  assert(!leaves.empty());
  if (leaves.size() == 1) {
    return leaves[0];
  }

  int nodeIndex = (int)c.size();

  c.emplace_back(0);
  for (int i = 0; i < (int)leaves.size(); ++i) {
    for (int j = i + 1; j < (int)leaves.size(); ++j) {
      c.back() = max(c.back(), a[leaves[i]][leaves[j]]);
    }
  }

  vector<vector<int>> childrenLeaves;
  for (int i = 0; i < (int)leaves.size(); ++i) {
    int u = leaves[i], g = -1;
    for (int j = 0; j < childrenLeaves.size(); ++j) {
      int v = childrenLeaves[j][0];
      if (a[u][v] != c.back()) {
        g = j;
        break;
      }
    }
    if (g == -1) {
      childrenLeaves.push_back({ u });
    } else {
      childrenLeaves[g].push_back(u);
    }
  }

  for (vector<int>& g : childrenLeaves) {
    e.emplace_back(f(g, c, e, a), nodeIndex);
  }

  return nodeIndex;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> c(n), leaves(n);
  for (int i = 0; i < n; ++i) {
    c[i] = a[i][i];
    leaves[i] = i;
  }

  vector<pair<int, int>> e;

  f(leaves, c, e, a);

  cout << (int)c.size() << '\n';
  for (int x : c) {
    cout << x << ' ';
  }
  cout << '\n';

  cout << (int)n + 1 << '\n';
  for (auto [u, v] : e) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }

  return 0;
}