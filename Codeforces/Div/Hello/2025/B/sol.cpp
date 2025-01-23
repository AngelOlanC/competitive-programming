#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n, k;
  cin >> n >> k;

  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  int mx = -1;
  for (auto [a, b] : cnt) {
    if (mx == -1 || b > cnt[mx]) {
      mx = a;
    }
  }

  vector<int> v;
  for (auto [a, b] : cnt) {
    if (a != mx) {
      v.push_back(b);
    }
  }

  sort(v.begin(), v.end());

  int ans = (int)cnt.size();
  for (int i = 0; i < (int)v.size() && v[i] <= k; ++i) {
    k -= v[i];
    --ans;
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