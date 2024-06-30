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

ll n, m, k;

ll f(ll x) {
  ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    cnt += min(m, (x - 1) / i);
  }
  return cnt;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  ll l = 1, r = n * m;
  while (l < r) {
    ll m = (l + r + 1) / 2;

    ll i = f(m);   
    if (i < k) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << ENDL;

  return 0;
}