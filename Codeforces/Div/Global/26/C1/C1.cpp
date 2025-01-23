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

void solve(int t) {
  int n;
  cin >> n;
  int a[n + 1];
  FOR (i, 1, n + 1) {
    cin >> a[i];
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

  cout << k << ENDL;
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