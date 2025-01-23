#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
 
using i64 = long long;
 
constexpr int maxn = 2e5 + 1;
 
int n, k;
vector<int> g[maxn];
 
int subtreeSize[maxn], pathLengthCount[maxn];
bool alive[maxn];
 
i64 ans;
 
void dfsSize(int u, int p) {
  subtreeSize[u] = 1;
  for (int v : g[u]) {
    if (v != p && alive[v]) {
      dfsSize(v, u);
      subtreeSize[u] += subtreeSize[v];
    }
  }
}
 
int findCentroid(int u, int p, int fullSz) {
  for (int v : g[u]) {
    if (v != p && alive[v] && 2 * subtreeSize[v] >= fullSz) {
      return findCentroid(v, u, fullSz);
    }
  }
  return u;
}

int maxDepth;
 
void dfsSum(int u, int p, int d, int centroid) {
  if (d > k) {
    return;
  }
  maxDepth = max(maxDepth, d);
  ans += pathLengthCount[k - d];
  for (int v : g[u]) {
    if (v != p && alive[v]) {
      dfsSum(v, u, d + 1, centroid);
    }
  }
}
 
void dfsCount(int u, int p, int d, int centroid) {
  if (d > k) {
    return;
  }
  ++pathLengthCount[d];
  for (int v : g[u]) {
    if (v != p && alive[v]) {
      dfsCount(v, u, d + 1, centroid);
    }
  }
}
 
void decompose(int u) {
  dfsSize(u, -1);
  int centroid = findCentroid(u, -1, subtreeSize[u]);
 
  pathLengthCount[0] = 1;
 
  for (int v : g[centroid]) {
    if (alive[v]) {
      dfsSum(v, centroid, 1, centroid);
      dfsCount(v, centroid, 1, centroid);
    }
  }
  
  fill(pathLengthCount + 1, pathLengthCount + maxDepth + 1, 0);
  alive[centroid] = false;
 
  for (int v : g[centroid]) {
    if (alive[v]) {
      decompose(v);
    }
  }
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
 
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
 
  for (int i = 0; i < n; ++i) {
    alive[i] = true;
  }
 
  decompose(0);
 
  cout << ans << '\n';
 
  return 0;
}