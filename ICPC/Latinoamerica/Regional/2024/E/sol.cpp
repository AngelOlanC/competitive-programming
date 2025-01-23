#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (!*max_element(a.begin(), a.end())) {
    for (int i = 1; i <= n; ++i) {
      cout << i << " \n"[i == n];
    }
    return 0;
  }
  vector<int> next(n), prev(n);
  int last = 0;
  for (int i = 0; i < n; ++i) {
    prev[i] = last;
    if (a[i]) {
      last = i;
    }
  }
  last = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    next[i] = last;
    if (a[i]) {
      last = i;
    }
  }
  vector<int> ans(n);
  int curr = 1, lp = 0, l = a[0] ? 0 : next[0], rp = n - 1, r = a[n - 1] ? n - 1 : prev[n - 1];
  while (l != r) {
    if (a[l] < a[r] && (lp != l || curr == a[l])) {
      ans[lp] = curr; 
      ++lp;
      ++curr;
      if (lp == l + 1) {
        l = next[l];
      }
      continue;
    }
    if (a[r] < a[l] && (rp != r || curr == a[r])) {
      ans[rp] = curr; 
      --rp;
      ++curr;
      if (rp == r - 1) {
        r = prev[r];
      }
      continue;
    }
    if (a[l] < a[r]) {
      if (rp == r) {
        cout << "*\n";
        return 0;
      }
      ans[rp] = curr; 
      --rp;
      ++curr;
      if (rp == r - 1) {
        r = prev[r];
      }
      continue;
    }
    if (lp == l) {
      cout << "*\n";
      return 0;
    }
    ans[lp] = curr; 
    ++lp;
    ++curr;
    if (lp == l + 1) {
      l = next[l];
    }
  }
  int mid = l;
  if (mid - lp < rp - mid) {
    while (lp < mid) {
      ans[lp] = curr;
      ++lp;
      ++curr;
    }
    while (rp > mid) {
      if (lp == mid && a[mid] == curr) {
        ans[lp] = curr;
        ++lp;
      } else {
        ans[rp] = curr;
        --rp;
      }
      ++curr;
    }
    if (lp == mid) {
      ans[lp] = curr;
    }
  } else {
    while (rp > mid) {
      ans[rp] = curr;
      --rp;
      ++curr;
    }
    while (lp < mid) {
      if (rp == mid && a[mid] == curr) {
        ans[rp] = curr;
        --rp;
      } else {
        ans[lp] = curr;
        ++lp;
      }
      ++curr;
    }
    if (rp == mid) {
      ans[rp] = curr;
    }
  }
  bool decreasing = false;
  for (int i = 0; i < n - 1; ++i) {
    decreasing |= ans[i] > ans[i + 1];
    if (!ans[i] || (decreasing && ans[i] < ans[i + 1]) || (a[i] && a[i] != ans[i])) {
      cout << "*\n";
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}