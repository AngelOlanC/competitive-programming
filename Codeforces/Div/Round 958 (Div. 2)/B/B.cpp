#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int test_case) {
  int n;
  cin >> n;
  vi c(2);
  int last_zero = 0;
  FOR (i, 0, n) {
    char ch;
    cin >> ch;
    if (ch == '0') {
      if (last_zero) continue;
      last_zero = 1;
    } else {
      last_zero = 0;
    }
    c[ch - '0']++;
  }
  cout << (c[1] > c[0] ? "Yes" : "No") << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}