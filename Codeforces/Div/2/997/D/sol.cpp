#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  i64 ans = (i64)n * (n + 1) >> 1;
  for (int x = 1; x <= 10; ++x) {
    map<int, int> mp;
    vector<int> p(n + 1);
    int ptr = 0;
    for (int i = 1; i <= n; ++i) {
      p[i] = p[i - 1];
      if (a[i] > x) {
        ++p[i];
      } else {
        --p[i];
        if (a[i] == x) {
          while (ptr < i) {
            ++mp[p[ptr++]];
          }
        }
      }
      ans -= mp[p[i]];
    }
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