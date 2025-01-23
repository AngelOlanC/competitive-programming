#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      pq.push({-x, -i});
    }
    int mx = -1;
    while (!pq.empty()) {
      auto [x, i] = pq.top();
      pq.pop();
      x *= -1;
      i *= -1;
      if (i < mx) {
        pq.push({-(x + 1), -n});
        continue;
      }
      mx = max(mx, i);
      cout << x << ' ';
    }
    cout << '\n';
  }
}