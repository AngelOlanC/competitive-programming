#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<int> cnt(26);
  for (int i = n - 1; i >= 0; --i) {
    if (cnt[s[i] - 'A']) {
      cout << i + 1 << '\n';
      return 0;
    }
    ++cnt[s[i] - 'A'];
  }
  assert(false);
  return 0;
}