#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr ll INF = 1e15;

void solve(int test_case) {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  FOR (i, 0, n) cin >> a[i];
  sort(ALL(a));
  vi p(k + 1);
  p[0]++;
  FOR (i, 1, n) {
    ll aux = (a[i] - a[0] + k - 1) / k;
    ll x = 1ll * k * aux + a[0], d = x - a[i];
    // cout << i << ' ';
    if (aux & 1) {
      if (a[i] == x) {
        cout << -1 << ENDL;
        return;
      }
      // cout << "incr " << k - d - 1 << ENDL;
      p[k - d]++;
    } else {
      p[0]++;
      p[k - d]--;
      // cout << "inc " << 0  << ENDL;
    }
  }
  ll aux = (a.back() - a[0] + k - 1) / k;
  ll x = 1ll * k * aux + a[0];
  FOR (i, 1, k) p[i] += p[i - 1];
  if (aux & 1) {
    ll mn = INF;
    FOR (i, 1, k + 1) {
      if (x - i < a.back()) break;
      if (p[k - i] == n) mn = min(mn, x - i);
    }
    if (mn == INF) mn = -1;
    cout << mn << ENDL;
    return;
  } 
  // cout << "par ";
  FOR (i, 0, k) if (p[i] == n) {
    cout << x + i << ENDL;
    return;H
  }
  cout << -1 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}