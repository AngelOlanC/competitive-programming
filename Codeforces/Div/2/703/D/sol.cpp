#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

bool ok(int m, vector<int>& a, int k) {
  const int n = (int)a.size();

  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1];
    if (a[i - 1] < m) {
      --p[i];
    } else {
      ++p[i];
    }
  }

  int mn = 1e9;
  for (int i = k; i <= n; ++i) {
    mn = min(mn, p[i - k]);
    if (p[i] - mn > 0) {
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  int l = 1, r = n;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (ok(m, a, k)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << '\n';

  return 0;
}