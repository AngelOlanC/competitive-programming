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

constexpr int maxn = 1e7 + 1;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi cnt(maxn);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  vi prime(maxn, 1);
  bool all = 0;
  FOR (i, 2, maxn) if (prime[i]) {
    int c = 0;
    for (int j = i; j < maxn; j += i) {
      c += cnt[j];
      prime[j] = 0;
    }
    
    if (all && c > 1) {
      cout << "NO" << ENDL;
      return 0;
    }
    if (c == n) all = 1;
  }
  string ans = all ? "YES" : "NO";
  cout << ans << ENDL;
  return 0;
}