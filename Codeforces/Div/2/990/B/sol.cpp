#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vi cnt(26, 0);
    for (int i = 0; i < n; ++i) {
      cnt[s[i] - 'a']++;
    }
    char mx_c, mn_c;
    int mn = 1e9, mx = 0;
    for (int i = 0; i < 26; ++i) {
      if (!cnt[i]) {
        continue;
      }
      if (cnt[i] < mn) {
        mn = cnt[i];
        mn_c = char('a' + i);
      }
      if (cnt[i] > mx) {
        mx = cnt[i];
        mx_c = char('a' + i);
      }
    }
    if (mn_c == mx_c) {
      for (int i = 0; i < n; ++i) {
        if (s[i] != mn_c) {
          s[i] = mn_c;
          break;
        }
      }
      cout << s << '\n';
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == mn_c) {
        s[i] = mx_c;
        break;
      }
    }
    cout << s << '\n';
  }
  return 0;
}