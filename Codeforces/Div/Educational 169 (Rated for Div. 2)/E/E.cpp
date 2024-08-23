#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

  int maxn = 1e7 + 1;
  vi nimber(maxn, 0);
  nimber[1] = 1;
  {
    vi vis(maxn, 0);
    int cnt_primes = 0;
    for (int i = 2; i < maxn; ++i) if (!vis[i]) {
      nimber[i] = ++cnt_primes;
      for (int j = 2 * i; j < maxn; j += i) if (!vis[j]) {
        vis[j] = 1;
        nimber[j] = cnt_primes; 
      }
    }
    for (int i = 2; i < maxn; i += 2) nimber[i] = 0;
  }

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    int n;
    cin >> n;
    int nim_sum = 0;
    FOR (i, 0, n) {
      int x;
      cin >> x;
      nim_sum ^= nimber[x];
    }
    cout << (nim_sum != 0 ? "Alice" : "Bob") << ENDL;
  }

  return 0;
}