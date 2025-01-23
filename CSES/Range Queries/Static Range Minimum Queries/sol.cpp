#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void f(int L, int R, vector<int>& a, vector<tuple<int, int, int>>& q, vector<int>& ans) {
  if (L == R) {
    for (auto [l, r, i] : q) {
      ans[i] = a[l];
    }
    return;
  }

  int m = (L + R) >> 1;
  
  vector<tuple<int, int, int>> ql, qr;
  for (auto [l, r, i] : q) {
    if (r <= m) {
      ql.emplace_back(l, r, i);
    } else if (l > m) {
      qr.emplace_back(l, r, i);
    }
  }

  f(L, m, a, ql, ans);
  f(m + 1, R, a, qr, ans);

  vector<int> stl(m - L + 1);
  stl.back() = a[m];
  for (int i = m - 1; i >= L; --i) {
    stl[i - L] = min(stl[i - L + 1], a[i]);
  }

  vector<int> str(R - m);
  str[0] = a[m + 1];
  for (int i = m + 2; i <= R; ++i) {
    str[i - m - 1] = min(str[i - m - 2], a[i]);
  }

  for (auto [l, r, i] : q) {
    if (l <= m && r > m) {
      ans[i] = min(stl[l - L], str[r - m - 1]);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  vector<tuple<int, int, int>> Q(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    Q[i] = {l, r, i};
  }

  vector<int> ans(q);
  f(0, n - 1, a, Q, ans);

  for (int x : ans) {
    cout << x << '\n';
  }
  cout << '\n';

  return 0;
}