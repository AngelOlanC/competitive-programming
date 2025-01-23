#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p[i] ^= p[i - 1];
  }

  i64 ans = 0;
  vector<vector<int>> c(2, vector<int>(1 << 21));
  for (int i = 0; i <= n; ++i) {
    ans += c[i & 1][p[i]];
    ++c[i & 1][p[i]];
  }
  cout << ans << '\n';

  return 0;
}