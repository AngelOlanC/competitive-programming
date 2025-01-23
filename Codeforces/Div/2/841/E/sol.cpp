#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  int n;
  i64 m;
  cin >> n >> m;

  vector<i64> cnt(n + 1);
  for (int i = n; i >= 1; --i) {
    int x = n / i;
    cnt[i] = (i64)x * (x - 1) >> 1;
    for (int j = 2 * i; j <= n; j += i) {
      cnt[i] -= cnt[j];
    }
  }

  i64 ans = m;
  for (int i = n; i > 1; --i) {
    i64 aux = min(m / (i - 1), cnt[i] / (i - 1));
    m -= aux * (i - 1);
    ans += aux;
  }
  
  if (m) {
    ans = -1;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}