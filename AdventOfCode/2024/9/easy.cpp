#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string line;
  cin >> line;
  vector<int> a;
  for (int i = 0, id = 0; i < (int)line.size(); i += 2) {
    int d = line[i] - '0';
    for (int i = 0; i < d; ++i) {
      a.push_back(id);
    }
    ++id;
    if (i + 1 == line.size()) {
      break;
    }
    d = line[i + 1] - '0';
    for (int i = 0; i < d; ++i) {
      a.push_back(-1);
    }
  }
  int n = a.size();
  int l = 0;
  for (int r = n - 1; l < r; --r) {
    if (a[r] == -1) {
      continue;
    }
    while (l < r && a[l] != -1) {
      ++l;
    }
    if (l == r) {
      break;
    }
    swap(a[l], a[r]);
  }
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != -1) {
      ans += (i64)i * a[i];
    }
  }
  cout << ans << '\n';
}