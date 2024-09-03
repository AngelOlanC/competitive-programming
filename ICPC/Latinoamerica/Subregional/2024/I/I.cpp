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

constexpr int maxvalue = 1e6 + 5, MOD = 1e9 + 7;

int be(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = (ll)res * a % MOD;
    a = (ll)a * a % MOD;
    b >>= 1;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vi> pd(maxvalue);
  pd[1].pb(1);
  {
    FOR (i, 2, maxvalue) if (pd[i].empty()) {
      pd[i].pb(i);
      for (int j = 2 * i; j < maxvalue; j += i) pd[j].pb(i);
    }
  }  

  int n;
  cin >> n;
  vi a(n), mul(maxvalue);
  FOR (i, 0, n) {
    cin >> a[i];
    mul[a[i]]++;
  }

  FOR (i, 1, maxvalue) for (int j = 2 * i; j < maxvalue; j += i) {
    mul[i] += mul[j];
  }

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    int pot = 0;
    FOR (msk, 0, 1 << 8) {
      int l = 
      FOR (i, 0, SZ(pd[x])) {

      }
    }
  }

  return 0;
}