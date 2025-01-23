#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> suf_ones(n);
    suf_ones.back() = s.back() == '1';
    for (int i = n - 2; i >= 0; --i) {
      suf_ones[i] = suf_ones[i + 1] + (s[i] == '1'); 
    }
    priority_queue<int> pq;
    for (int i = 1; i < n; ++i) {
      int zeroes = n - i - suf_ones[i];
      if (suf_ones[i]) {
        pq.push(suf_ones[i] - zeroes);
      }
    }
    int ans = 1, dif = 0;
    while (!pq.empty() && dif < k) {
      dif += pq.top();
      pq.pop();
      ++ans;
    }
    if (dif < k) {
      ans = -1;
    }
    cout << ans << '\n';
  }
  return 0;
} 