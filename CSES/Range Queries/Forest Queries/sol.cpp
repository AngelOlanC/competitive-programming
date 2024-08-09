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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<string> a(n);
  FOR (i, 0, n) cin >> a[i];

  vector<vi> p(n + 5, vi(n + 5));
  FOR (i, 0, n + 5) {
    FOR (j, 0, n + 5) {
      if (i < n && j < n) p[i + 1][j + 1] += a[i][j] == '*';
      if (i) p[i][j] += p[i - 1][j];
      if (j) p[i][j] += p[i][j - 1];
      if (i && j) p[i][j] -= p[i - 1][j - 1];
    }
  }
  while (q--) {
    int i, j, k, l;
    cin >> i >> j >> k >> l;
    cout << p[k][l] - p[k][j - 1] - p[i - 1][l] + p[i - 1][j - 1] << ENDL;
  }

  return 0;
}