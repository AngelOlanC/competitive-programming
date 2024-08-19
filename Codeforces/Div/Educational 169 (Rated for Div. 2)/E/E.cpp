#include <bits/stdc++.h>
using namespace std;
// AC2#
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
  int ones = 0;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    ones += x == 1;
  }
  if (n == 1)
  cout << (ones & 1 && (n - ones) & 1 ? "Alice" : "Bob") << ENDL;
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