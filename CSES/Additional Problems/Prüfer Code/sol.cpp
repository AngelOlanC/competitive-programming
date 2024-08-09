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

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
  int n = code.size() + 2;
  vector<int> degree(n, 1);
  for (int i : code)
      degree[i]++;

  int ptr = 0;
  while (degree[ptr] != 1)
      ptr++;
  int leaf = ptr;

  vector<pair<int, int>> edges;
  for (int v : code) {
      edges.emplace_back(leaf, v);
      if (--degree[v] == 1 && v < ptr) {
          leaf = v;
      } else {
          ptr++;
          while (degree[ptr] != 1)
              ptr++;
          leaf = ptr;
      }
  }
  edges.emplace_back(leaf, n-1);
  return edges;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n - 2);
  for (auto &ai : a) {
    cin >> ai;
    ai--;
  }

  vector<pi> g = pruefer_decode(a);

  for (auto &[u, v] : g) {
    cout << u + 1 << ' ' << v + 1 << ENDL;
  }

  return 0;
}