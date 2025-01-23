#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
  int n;
  i64 k;
  cin >> n >> k;
  if (n == 1) {
    if (k == 1) {
      cout << "1\n";
      return;
    }
    cout << "-1\n";
    return;
  }
  vector<int> front, back;
  int i = 0;
  while (n - i >= 50) {
    front.push_back(i);
    ++i;
  }
  i64 pot = 1;
  for (int j = 0; j < n - i - 2; ++j) {
    pot *= 2;
  }
  while (i < n) {
    if (pot < k) {
      back.push_back(i);
      k -= pot;
    } else {
      front.push_back(i);
    }
    pot >>= 1;
    ++i;
  }
  if (k != 1) {
    cout << "-1\n";
    return;
  }
  reverse(back.begin(), back.end());
  for (int x : front) {
    cout << x + 1 << ' ';
  }
  for (int x : back) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}