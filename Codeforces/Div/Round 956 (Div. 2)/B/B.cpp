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

  vector<vi> a(n, vi(m)), b(n, vi(m));
  FOR (i, 0, n) FOR (j, 0, m){
    char c;
    cin >> c;
    a[i][j] = c - '0';
  }
  FOR (i, 0, n) FOR (j, 0, m){
    char c;
    cin >> c;
    b[i][j] = c - '0';
  }

  FOR (i, 0, n) {
    ll s = 0;
    FOR (j, 0, m) {
      s += 3 + a[i][j] - b[i][j];
    }
    if (s % 3) {
      cout << "NO" << ENDL;
      return;
    }  
  }

  FOR (j, 0, m) {
    ll s = 0;
    FOR (i, 0, n) {
      s += 3 + a[i][j] - b[i][j];
    }
    if (s % 3) {
      cout << "NO" << ENDL;
      return;
    }
  }

  cout << "YES" << ENDL;
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