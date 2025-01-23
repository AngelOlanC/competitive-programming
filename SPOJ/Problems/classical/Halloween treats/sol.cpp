#include <bits/stdc++.h>
using namespace std;

void solve(int c, int n) {
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i] %= c;
    if (i) {
      p[i] = (p[i] + p[i - 1]);
      if (p[i] >= c) {
        p[i] -= c;
      }
    }
  }
  vector<int> last(c, -1);
  for (int i = 0; i < n; ++i) {
    if (!p[i]) {
      for (int j = 0; j <= i; ++j) {
        cout << j + 1 << " \n"[j == i];
      }
      return;
    }
    if (last[p[i]] == -1) {
      last[p[i]] = i;
      continue;
    }
    for (int j = last[p[i]] + 1; j <= i; ++j) {
      cout << j + 1 << " \n"[j == i];
    }
    return;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int c, n;
  while (cin >> c >> n) {
    solve(c, n);   
  }
}