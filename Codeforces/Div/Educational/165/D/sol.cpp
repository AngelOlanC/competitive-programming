#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), b(n);
  for (int& x : a) {
    cin >> x;
  }
  for (int& x : b) {
    cin >> x;
  }

  if (!k) {
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] > a[i]) {
        ans += b[i] - a[i];
      }
    }
    cout << ans << '\n';
    return;
  }

  {
    vector<int> c, d;
    for (int i = 0; i < n; ++i) {
      if (b[i] > a[i]) {
        c.push_back(a[i]);
        d.push_back(b[i]);
      }
    }
    a.swap(c);
    b.swap(d);
  }
  n = (int)a.size();

  if (n <= k) {
    cout << 0 << '\n';
    return;
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] > b[j]; });

  multiset<int> mst;
  i64 curr = 0;
  for (int i = 0; i < k; ++i) {
    mst.insert(a[ord[i]]);
    curr -= a[ord[i]];
  }
  for (int i = k; i < n; ++i) {
    curr += b[ord[i]] - a[ord[i]];
  }

  i64 ans = max(0ll, curr);
  for (int i = k; i < n; ++i) {
    curr -= b[ord[i]] - a[ord[i]];
    if (a[ord[i]] < *mst.rbegin()) {
      curr += *mst.rbegin() - a[ord[i]];
      mst.erase(mst.find(*mst.rbegin()));
      mst.insert(a[ord[i]]);
    }
    ans = max(ans, curr);
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