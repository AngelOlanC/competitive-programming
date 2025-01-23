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
  int xc, yc, k;
  cin >> xc >> yc >> k;
  int old_k = k;
  if (k & 1) {
    int num = 1e8;
    while (k != 1) {
      cout << num << ' ' << num << ENDL;
      cout << -num << ' ' << -num << ENDL;
      num--;
      k -= 2;
    }
    cout << (ll)xc * old_k << ' ' << (ll)yc * old_k << ENDL;
    return;
  }
  int num = 1e8;
  while (k != 2) {
    cout << num << ' ' << num << ENDL;
    cout << -num << ' ' << -num << ENDL;
    num--;
    k -= 2;
  }
  if (xc == 0 && yc == 0) {
    cout << num << ' ' << num << ENDL;
    cout << -num << ' ' << -num << ENDL;
    return;
  }
  cout << "0 0" << ENDL;
  cout << (ll)xc * old_k << ' ' << (ll)yc * old_k << ENDL;
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