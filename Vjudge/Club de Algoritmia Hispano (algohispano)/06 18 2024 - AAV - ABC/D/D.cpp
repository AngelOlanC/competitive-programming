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

constexpr ll MOD = 998244353;

/**
 * Descripcion: Calcula a^b mod m
 * Tiempo: O(log b)
 */
ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;

  ll y = 1;

  while (x) {
    x /= 10;
    y = y * 10 % MOD;
  }

  ll ans = n * (be(y, n) - 1 + MOD) % MOD;
  ans *= 

  return 0;
}