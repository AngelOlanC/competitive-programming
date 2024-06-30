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

ll h[200005];
ll p[200005];
int n;

ll calc() {
  p[n + 2] = p[n + 1] = p[n] = p[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    ll x = max({0LL, h[i - 1] + 1 - h[i], h[i + 1] + 1 - h[i]});
    p[i] = x + p[i + 2];
  }
  ll ans = 1e18, sum = 0;
  for (int i = 1; i < n; i += 2) {
    ll x = max({0LL, h[i - 1] + 1 - h[i], h[i + 1] + 1 - h[i]});
    sum += x;
    ans = min(ans, sum + p[i + 3]);
  }
  return min(ans, p[2]);
}

void solve(int t) {
  cin >> n;

  FOR (i, 0, n) {
    cin >> h[i];
  }

  if (n & 1) {
    ll ans = 0;
    for (int i = 1; i < n; i += 2) {
      ans += max({0LL, h[i - 1] + 1 - h[i], h[i + 1] + 1 - h[i]});
    }
    cout << ans << ENDL;
    return;
  }

  ll ans = calc();
  reverse(h, h + n);
  cout << min(ans, calc()) << ENDL;
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