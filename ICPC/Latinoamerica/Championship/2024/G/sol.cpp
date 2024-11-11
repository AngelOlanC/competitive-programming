#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ld = long double;
using i64 = long long;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << setprecision(12) << fixed;

  int N;
  cin >> N;
  vector<int> W(N + 1);
  int S = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> W[i];
    S += W[i];
  }

  vector<ld> p(N + 1);
  for (int i = 1; i <= N; ++i) {
    p[i] = (ld)W[i] / S;
  }

  vector<vector<int>> g(N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; j += i) {
      g[j].push_back(i);
    }
  }

  vector<ld> E(N + 1);
  for (int i = N; i >= 1; --i) {
    int D = 0;
    for (auto &u : g[i]) {
      D += W[u];
    }
    ld C = (ld)D / S, aux = 0;
    for (int j = 2 * i, k = 2; j <= N; j += i, ++k) {
      for (auto &u : g[i]) {
        i64 x = (i64)u * k;
        if (lcm(x, i) == j) {
          E[i] += p[x] * (E[j] + 1);
          aux += p[x];
        }
      }
    }
    E[i] += 1.0 - aux;
    E[i] /= (1 - C);
  }
  cout << E[1] - 1 << '\n';

  return 0;
}