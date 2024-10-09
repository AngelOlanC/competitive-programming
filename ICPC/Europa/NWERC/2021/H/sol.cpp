#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  FOR (i, 0, n) cin >> a[i];
  
  auto f = [&](ll c) -> bool {
    vi l(n), r(n);
    vector<ll> x(n), y(n);
    FOR (i, 0, n) {
      l[i] = (i - 1 + n) % n;
      r[i] = (i + 1) % n;
      x[i] = y[i] = a[i];
    }
    vi out(n);
    int k = n - 1;
    FOR (i, 0, n) if (!out[i] && x[i] <= c) while (i != l[i]) {
      if (x[l[i]] <= y[i] + c) {
        y[i] += y[l[i]];
        x[i] = min(x[i], x[l[i]]);
        r[l[l[i]]] = i;
        out[l[i]] = 1;
        l[i] = l[l[i]];
        --k;
        continue;
      }
      if (x[r[i]] <= y[i] + c) {
        y[i] += y[r[i]];
        x[i] = min(x[i], x[r[i]]);
        l[r[r[i]]] = i;
        out[r[i]] = 1;
        r[i] = r[r[i]];
        --k;
        continue;
      }
      break;
    }
    return !k;
  };

  ll l = 0, r = *max_element(ALL(a));
  while (l < r) {
    ll m = l + (r - l) / 2;
    if (f(m)) r = m;
    else l = m + 1;
  }
  cout << l << ENDL;

  return 0;
}