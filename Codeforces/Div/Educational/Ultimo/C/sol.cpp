#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void solve() {
  int n;
  cin >> n;

  int k = n + 1;
  vector<int> a(n + 1), p(n + 1), p1(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > 1 || a[i] < -1) {
      k = i;
    } else {
      p1[i] = p1[i - 1] + a[i];
    }
    p[i] = p[i - 1] + a[i];
  }

  int mx_p = 0, mn_p = 0, lo = 0, hi = 0; 
  for (int i = 1; i < k; ++i) {
    hi = max(hi, p1[i] - mn_p);
    lo = min(lo, p1[i] - mx_p);

    mx_p = max(mx_p, p1[i]);
    mn_p = min(mn_p, p1[i]);
  }

  mx_p = 0;
  mn_p = 0;
  for (int i = k + 1; i <= n; ++i) {
    hi = max(hi, p1[i] - mn_p);
    lo = min(lo, p1[i] - mx_p);
    
    mx_p = max(mx_p, p1[i]);
    mn_p = min(mn_p, p1[i]);
  }

  set<int> ans;
  for (int i = lo; i <= hi; ++i) {
    ans.insert(i);
  }

  if (k != n + 1) {
    mn_p = 0;
    mx_p = 0;
    for (int i = 1; i < k; ++i) {
      mn_p = min(mn_p, p[i]);
      mx_p = max(mx_p, p[i]);
    }

    lo = a[k];
    hi = a[k];
    for (int i = k; i <= n; ++i) {
      hi = max(hi, p[i] - mn_p);
      lo = min(lo, p[i] - mx_p);
    }

    for (int i = lo; i <= hi; ++i) {
      ans.insert(i);
    }
  }
  cout << (int)ans.size() << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
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