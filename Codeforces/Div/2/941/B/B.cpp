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
  int n, m;
  cin >> n >> m;

  char c[n][m];
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> c[i][j];
    }
  }

  bool side[4][2];
  memset(side, 0, sizeof side);
  FOR (i, 0, n) {
    side[0][0] |= c[i][0] == 'W'; 
    side[0][1] |= c[i][0] == 'B';

    side[2][0] |= c[i][m - 1] == 'W'; 
    side[2][1] |= c[i][m - 1] == 'B';
  }
  
  FOR (j, 0, m) {
    side[1][0] |= c[0][j] == 'W'; 
    side[1][1] |= c[0][j] == 'B';

    side[3][0] |= c[n - 1][j] == 'W'; 
    side[3][1] |= c[n - 1][j] == 'B';
  }

  bool can = side[0][1] && side[1][1] && side[2][1] && side[3][1];
  can |= side[0][0] && side[1][0] && side[2][0] && side[3][0];
  cout << (can ? "YES" : "NO") << ENDL;
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