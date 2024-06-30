#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int t) {
  int n;
  cin >> n;
  int last[25];
  FOR (i, 0, 25) {
    last[i] = -1;
  }
  
  int ans = 1;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    FOR (j, 0, 25) {
      if ((x >> j) & 1) {
        ans = max(ans, i - last[j]);
        last[j] = i;
      }
    }
  }
  FOR (j, 0, 25) {
    if (last[j] != -1) {
      ans = max(ans, n - last[j]);
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  FOR (i, 0, t) {
    solve(t + 1);  
  }

  return 0;
}