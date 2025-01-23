#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach moy
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> diag;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '/') {
      diag.push_back(i);
    }
  }
  vector<int> p1(n), p2(n);
  p1[0] = s[0] == '1';
  p2[0] = s[0] == '2';
  for (int i = 1; i < n; ++i) {
    p1[i] = p1[i - 1] + (s[i] == '1');
    p2[i] = p2[i - 1] + (s[i] == '2');
  }
  auto sum = [](vector<int>& p, int l, int r) -> int {
    return p[r] - (l ? p[l - 1] : 0);
  };
  auto get = [&](int l, int r, int m) -> int {
    return min(sum(p1, l, m), sum(p2, m, r));
  };
  while (q--) {
    int L, R;
    cin >> L >> R;
    --L;
    --R;
    int l = lower_bound(diag.begin(), diag.end(), L) - diag.begin();
    if (l == (int)diag.size() || diag[l] > R) {
      cout << "0\n";
      continue;
    }
    int r = upper_bound(diag.begin(), diag.end(), R) - diag.begin() - 1;
    while (r - l > 1) { 
      int m = (l + r) / 2;
      if (sum(p1, L, diag[m]) <= sum(p2, diag[m], R)) {
        l = m;
      } else {
        r = m;
      }
    }
    int len = max(get(L, R, diag[l]), get(L, R, diag[r]));
    cout << 2 * len + 1 << '\n';
  }
}