#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

template <class T>
struct SubMatrix {
  vector<vector<T>> p;
  SubMatrix(vector<vector<T>>& v) {
    ll R = SZ(v), C = SZ(v[0]);
    p.assign(R + 1, vector<T>(C + 1));
    FOR(r, 0, R)
    FOR(c, 0, C)
    p[r + 1][c + 1] = v[r][c] + p[r][c + 1] + p[r + 1][c] - p[r][c];
  }
  T sum(ll u, ll l, ll d, ll r) {
    return p[d][r] - p[d][l] - p[u][r] + p[u][l];
  }
};

void solve(ll tc) {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vi> a(n, vi(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> a[i][j];
    }
  }
  ll s0 = 0, s1 = 0;
  vector<vi> t0(n, vi(m, 0)), t1(n, vi(m, 0));
  vector<vi> t(n, vi(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      char ch;
      cin >> ch;
      t[i][j] = ch - '0';
      if (t[i][j]) {
        t0[i][j] = 1;
        s0 += a[i][j];
      } else {
        t1[i][j] = 1;
        s1 += a[i][j];
      }
    }
  }
  ll d = s0 - s1;
  if (d == 0) {
    cout << "YES" << ENDL;
    return;
  }
  SubMatrix sm0 = SubMatrix<ll>(t0), sm1 = SubMatrix<ll>(t1);
  ll g = 0;
  FOR (i, 0, n - k + 1) {
    FOR (j, 0, m - k + 1) {
      ll c0 = sm0.sum(i, j, i + k, j + k);
      ll c1 = sm1.sum(i, j, i + k, j + k);

      if (c0 != c1) {
        g = gcd(g, c0 - c1);
      }
    }
  }
  cout << (g && d % g == 0 ? "YES" : "NO") << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  FOR (i, 0, t) {
    solve(i + 1);  
  }

  return 0;
}