#include <bits/stdc++.h>
using namespace std;

using i64 = long long;


signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), pre_a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre_a[i] = pre_a[i - 1] + a[i];
  }
  vector<i64> s(n + 1);
  s[n] = a[n];
  for (int i = n - 1; i >= 1; --i) {
    s[i] = s[i + 1] + (i64)(n - i) * a[i] + a[i];
  }
  vector<i64> pre_s(n + 1);
  for (int i = 1; i <= n; ++i) {
    pre_s[i] = pre_s[i - 1] + s[i];
  }
  vector<i64> st(n + 1), en(n + 1);
  for (int i = 1; i <= n; ++i) {
    st[i] = en[i - 1] + 1;
    en[i] = st[i] + n - i;
  }
  vector<i64> ladder(n +2);
  ladder[n] = a[n];
  for (int i = n - 1; i >= 1; --i) {
    ladder[i] = ladder[i + 1] + (n - i + 1) * a[i];
  }
  auto get = [&](i64 x) -> int {
    int l = 1, r = n;
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if (st[m] <= x) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  };
  auto get_sub = [&](int start, int d) -> i64 {
    return ladder[start] - ladder[start + d] - (i64)(n - start + 1 - d) * (pre_a[start + d - 1] - pre_a[start - 1]);
  };
  int q;
  cin >> q;
  while (q--) {
    i64 l, r;
    cin >> l >> r;
    int a = get(l), b = get(r);
    i64 ans = pre_s[b] - pre_s[a - 1];
    ans -= get_sub(a, l - st[a]);
    ans -= get_sub(b, en[b] - st[b] + 1) - get_sub(b, r - st[b] + 1);
    cout << ans << '\n';
  }

  return 0;
}