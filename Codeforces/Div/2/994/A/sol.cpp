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
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
      cin >> x;
    }
    bool num = false, num_zero = false, num_zero_num = false;
    for (int& x : a) {
      if (!x) {
        if (num) {
          num_zero = true;
        }
      } else {
        num = true;
        if (num_zero) {
          num_zero_num = true;
        }
      }
    }
    if (!num) {
      cout << 0 << '\n';
      continue;
    }
    if (num_zero_num) {
      cout << 2 << '\n';
      continue;
    }
    cout << 1 << '\n';
  }

  return 0;
}