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

  vi pos[n];
  FOR (i, 0, n) {
    int x;
    cin >> x;
    pos[x - 1].pb(i);
  }

  FOR (i, 0, n) {
    reverse(ALL(pos[i]));

    vi c(2, 0);
    for (auto &x : pos[i]) {
      c[x % 2] = c[(x + 1) % 2] + 1;
    }
    cout << max(c[0], c[1]) << ' ';
  }
  cout << ENDL;
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