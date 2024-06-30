#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = unsigned long long;
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

ll mx = 1e12;
vector<ll> a;

void f(ll x) {
  if (x > mx) {
    return;
  }
  a.pb(x);
  f(x * 10 + 4);
  f(x * 10 + 7);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  f(0);

  sort(ALL(a));

  ll l, r;
  cin >> l >> r;

  ll ans = 0;
  int i = lower_bound(ALL(a), l) - a.begin();
  while (l <= r) {
    ans += (min(r, a[i]) - l + 1) * a[i];
    l = a[i] + 1;
    i++;
  }
  cout << ans << ENDL;

  return 0;
}