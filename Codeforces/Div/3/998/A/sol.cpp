#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int f(int x, vector<int>& a) {
  a[2] = x;
  int ret = 0;
  for (int i = 2; i < (int)a.size(); ++i) {
    if (a[i] == a[i - 1] + a[i - 2]) {
      ++ret;
    }
  }
  return ret;
}

void solve() {
  vector<int> a(5);
  cin >> a[0] >> a[1] >> a[3] >> a[4];
  
  cout << max({f(a[0] + a[1], a), f(a[3] - a[1], a), f(a[4] - a[3], a)}) << '\n';
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