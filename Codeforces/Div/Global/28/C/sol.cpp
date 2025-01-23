#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

bool is_better(string& s, int l, int r, int best_l, int best_r) {
  if (best_r - best_l != r - l) {
    return r - l > best_r - best_l;
  }
  int len = r - l + 1, n = (int)s.size();
  for (int i = 0; i < len; ++i) {
    bool diff1 = s[l + i] != s[n - len + i];
    bool diff2 = s[best_l + i] != s[n - len + i];
    if (diff1 != diff2) {
      return diff1;
    }
  }
  return true;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int best_l = 0, best_r = 0;
    int n = (int)s.size();
    for (int r = n - 1; r >= 0; --r) {
      int min_good_l = -1;
      for (int l = r; l >= 0; --l) {
        if (s[l] != s[n - (r - l) - 1]) {
          min_good_l = l;
        }
      }
      if (min_good_l == -1) {
        continue;
      }
      if (best_l == -1 || is_better(s, min_good_l, r, best_l, best_r)) {
        best_l = min_good_l;
        best_r = r;
      }
    }
    cout << 1 << ' ' << n << ' ' << best_l + 1 << ' ' << best_r + 1 << '\n';
  }

  return 0;
}