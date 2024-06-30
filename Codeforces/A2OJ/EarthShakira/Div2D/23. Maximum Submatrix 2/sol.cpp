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

  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (auto &ai : a) {
    for (auto &aij : ai) {
      cin >> aij;
    }
  }

  int ans = 0;
  vi p(m + 1, 0), l(n, 0);
  p[0] = n;
  ROF (j, m, 0) {
    FOR (i, 0, n) {
      p[l[i]]--;
      l[i] = a[i][j] == '1' ? l[i] + 1 : 0;
      p[l[i]]++;
    }
    int cnt = 0;
    FOR (k, 0, m - j + 1) if (p[k]) {
      ans = max(ans, k * (n - cnt));
      cnt += p[k];
    }
  }
  cout << ans << ENDL;

  return 0;
}