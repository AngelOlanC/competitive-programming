#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr int MX = 1e9;

void f(int L, int R, vector<int>& a, vector<i64>& p, set<int>& st) {
  i64 s = p[R] - p[L];

  if (st.empty() || s < *st.begin()) {
    return;
  }

  if (s <= MX) {
    st.erase(int(s));
  }

  int M = int(upper_bound(a.begin() + L, a.begin() + R, (a[L] + a[R - 1]) >> 1) - a.begin());

  if (M != L && M != R) {
    f(L, M, a, p, st);
    f(M, R, a, p, st);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  vector<i64> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + a[i - 1];
  }

  vector<int> Q(q);
  set<int> st;
  for (int& x : Q) {
    cin >> x;
    st.insert(x);
  }

  f(0, n, a, p, st);

  for (int x : Q) {
    cout << (st.find(x) == st.end() ? "Yes" : "No") << '\n';
  }
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