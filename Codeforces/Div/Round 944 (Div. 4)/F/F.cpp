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

int r;

bool muy_afuera(ll x, ll y) {
  ll d2 = x * x + y * y;
  ll r1 = (r + 1) * 1ll * (r + 1);
  return d2 >= r1;
}

bool al_cien(ll x, ll y) {
  ll d2 = x * x + y * y;
  ll r1 = r * 1ll * r;
  return d2 >= r1;
}

void solve(int t) {
  cin >> r;

  int x = -r - 1;
  ll ans = 0;
  for (int y = 0; y <= r; y++) {
    while (muy_afuera(x, y)) {
      x++;
    }
    int xx = x;
    while (xx <= 0 && al_cien(xx, y)) {
      ans++;
      xx++;
    }
  }
  cout << ans * 4 - 4 << ENDL;
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