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

constexpr ll MOD = 998244353;

ll be(ll a, ll b) {
  ll res = 1;
  a %= MOD;
  while (b) {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

void solve(int t) {
  int n;
  cin >> n;
  int a[n + 1];
  FOR (i, 1, n + 1) {
    cin >> a[i];
  }

  if (*min_element(a + 1, a + n + 1) >= 0) {
    cout << be(2, n) << ENDL;
    return;
  }

  ll prefix[n + 1];
  prefix[0] = 0;
  FOR (i, 1, n + 1) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  ll k = 0;
  FOR (i, 1, n + 1) {
    k = max(k, abs(prefix[i]) + prefix[n] - prefix[i]);
  }

  ll ans = 0, whatever = 0;
  FOR (i, 1, n + 1) {
    if (prefix[i] >= 0) {
      whatever++;
    }
    ll kk = abs(prefix[i]) + prefix[n] - prefix[i];
    if (kk == k) {
      ans = (ans + be(2, whatever) * be(2, n - i) % MOD) % MOD;
      if (i == 1 && whatever == 1) {
        break;
      }
    }
  }

  cout << ans << ENDL;
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