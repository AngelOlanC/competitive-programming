#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
  int n, k;
  cin >> n >> k;
  int x[n], y[n];
  FOR (i, 0, n) {
    cin >> x[i];
  }
  FOR (i, 0, n) {
    cin >> y[i];
  }

  vi a, b;
  FOR (i, 0, n) {
    if (y[i] - x[i] > 0) {
      a.pb(x[i]);
      b.pb(y[i]);
    }
  }

  n = SZ(a);

  if (n <= k) {
    cout << 0 << ENDL;
    return;
  }

  int c[n];
  FOR (i, 0, n) {
    c[i] = max(a[i], b[i] - a[i]);
  }

  int p[n];
  iota(p, p + n, 0);
  sort(p, p + n, [&](int i, int j) {
    return c[i] > c[j];
  });

  oset<pi> os;
  ll ls = 0;
  FOR (i, 0, k) {
    ls += a[p[i]];
    os.insert({c[p[i]], i});
  }

  ll rs = 0;
  FOR (i, k, n) {
    rs += b[p[i]] - a[p[i]];
  }

  if (k == 0) {
    cout << rs << ENDL;
    return;
  }

  ll ans = max(0LL, rs - ls);
  cout << ans << ' ' << ls << ' ' << rs << ENDL;
  FOR (i, k, n) {
    rs -= b[p[i]] - a[p[i]];
    
    auto last = os.find_by_order(k - 1);
    os.insert({c[p[i]], i});
    if (os.order_of_key({c[p[i]], i}) < k - 1) {
      ls += a[p[i]]; 
      ls -= a[p[last->second]];
    }
    ans = max(ans, rs - ls);
    cout << ans << ' ' << ls << ' ' << rs << ENDL;
  }
  cout << ans << ENDL << ENDL;
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