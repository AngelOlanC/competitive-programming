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
  int n, k;
  cin >> n >> k;

  vi ans;
  ans.pb(k + 1);
  int aux = k;
  FOR (i, 0, 20) {
    if (!((k >> i) & 1)) {
      ans.pb(1 << i);
      continue;
    }
    aux -= 1 << i;
    if (aux == 0) {
      ans.pb(k - (1 << i));
      ans.pb(k + 1 + (1 << i));
      continue;
    }
    ans.pb((1 << i));
  }

  cout << SZ(ans) << ENDL;
  for (auto &x : ans) {
    cout << x << ' ';
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