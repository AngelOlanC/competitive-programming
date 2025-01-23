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

  string s;
  cin >> s;

  int n = (int)s.size();

  vector<int> p(n);
  for (int i = 1; i < n; ++i) {
    int k = p[i - 1];
    while (k && s[k] != s[i]) {
      k = p[k - 1];
    }
    p[i] = k + (s[i] == s[k]);
  }

  vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    ++c[i];
  }
  for (int i = n; i >= 1; --i) {
    c[p[i - 1]] += c[i];
  }

  vector<pair<int, int>> ans;
  int k = n;
  while (k) {
    ans.push_back({k, c[k]});
    k = p[k - 1];
  }

  reverse(ans.begin(), ans.end());

  cout << (int)ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }

  return 0;
}