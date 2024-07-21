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
  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(m));
  pi lst = {0, 0};
  FOR (i, 0, n) FOR (j, 0, m) {
    cin >> a[i][j];
    swap(a[lst.first][lst.second], a[i][j]);
    lst = {i, j};
  }
  if (n == 1 && m == 1) a[0][0] = -1;
  FOR (i, 0, n) FOR (j, 0, m) cout << a[i][j] << " \n"[j == m - 1];
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