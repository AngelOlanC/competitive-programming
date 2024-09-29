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

constexpr int maxv = 1e6 + 5, MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vi> pd(maxv);
  {
    vi is_prime(maxv, 1);
    FOR (i, 2, maxv) if (is_prime[i]) for (int j = i; j < maxv; j += i) {
      is_prime[j] = 0;
      pd[j].pb(i);
    }
  }

  int n;
  cin >> n;

  vi ncp(maxv), a(n);
  for (auto &x : a) {
    cin >> x;
    FOR (msk, 1, (1 << SZ(pd[x]))) {
      int mul = 1;
      FOR (i, 0, SZ(pd[x])) if ((msk >> i) & 1) mul *= pd[x][i];
      ++ncp[mul];
    }
  }

  vi pot2(n + 1);
  pot2[0] = 1;
  FOR (i, 1, n + 1) pot2[i] = pot2[i - 1] * 2 % MOD;

  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    int cp = 0;
    FOR (msk, 1, (1 << SZ(pd[x]))) {
      int mul = 1;
      FOR (i, 0, SZ(pd[x])) if ((msk >> i) & 1) mul *= pd[x][i];
      cp += (__builtin_popcount(msk) % 2 ? ncp[mul] : -ncp[mul]);
    }
    cout << pot2[n - cp] << ENDL;
  }

  return 0;
}