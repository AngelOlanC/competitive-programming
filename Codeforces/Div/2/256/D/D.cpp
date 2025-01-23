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
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

ll n, m, k;
void check(ll i, ll j) {
  if (!k) {
    cout << i * j << ENDL;
    exit(0);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  if (n < m) {
    swap(n, m);
  }

  FOR (i, 1, n + 1) {
    ll x = min(i, m);
    if (k - x > 0) {
      k -= x;
      continue;
    }
    ll j = 1;
    if (i > m) {
      k--;
      check(i--, j++);
      continue;
    }
    k--;
    check(i, j);
    k--;
    check(i--, j++);
  }

  return 0;
}