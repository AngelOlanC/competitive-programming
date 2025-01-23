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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--, b--, c--, d--;

  vi left(12, 0);
  vi right(12, 0);

  for (int i = (a + 11) % 12; i != b; i = (i + 11) % 12) {
    left[i] = 1;
  }

  for (int i = (a + 1) % 12; i != b; i = (i + 1) % 12) {
    right[i] = 1;
  }

  cout << ((left[c] && right[d]) || (left[d] && right[c]) ? "YES" : "NO") << ENDL;
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