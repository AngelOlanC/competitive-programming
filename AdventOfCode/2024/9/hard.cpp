#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string line;
  cin >> line;
  vector<pair<int, int>> a;
  for (int i = 0, id = 0; i < (int)line.size(); i += 2) {
    int d = line[i] - '0';
    a.push_back({d, id});
    ++id;
    if (i + 1 == line.size()) {
      break;
    }
    d = line[i + 1] - '0';
    a.push_back({d, -1});
  }
  int n = a.size();
  for (int r = n - 1; r >= 0; --r) {
    if (a[r].second == -1) {
      continue;
    }
    int lg = -1;
    for (int l = 0; l < r; ++l) {
      if (a[l].second == -1 && a[l].first >= a[r].first) {
        lg = l;
        break;
      }
    }
    if (lg == -1) {
      continue;
    }
    for (int i = r; i > lg; --i) {
      swap(a[i], a[i - 1]);
    }
    a[lg + 1].first -= a[lg].first;
    a.insert(a.begin() + r, {a[lg].first, -1});
  }
  vector<int> b;
  for (auto [c, x] : a) {
    while (c--) {
      b.push_back(x);
    }
  }
  i64 ans = 0;
  for (int i = 0; i < (int)b.size(); ++i) {
    if (b[i] != -1) {
      ans += (i64)i * b[i];
    }
  }
  cout << ans << '\n';
}