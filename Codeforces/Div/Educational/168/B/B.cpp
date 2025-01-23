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
  vector<vector<char>> a(2, vector<char>(n));
  FOR (i, 0, 2) FOR (j, 0, n) cin >> a[i][j];
  int ans = 0;
  FOR (j, 1, n - 1) {
    ans += a[0][j - 1] == '.' && a[0][j] == '.' && a[0][j + 1] == '.' && a[1][j] == '.' && a[1][j - 1] == 'x' && a[1][j + 1] == 'x';
    ans += a[1][j - 1] == '.' && a[1][j] == '.' && a[1][j + 1] == '.' && a[0][j] == '.' && a[0][j - 1] == 'x' && a[0][j + 1] == 'x';
  }
  cout << ans << ENDL;
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