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

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= SZ(s) && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    return pos;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, a, b;
  cin >> n >> a >> b;
  a--, b--;

  FT ft(n);
  FOR (i, 0, n) {
    ft.update(i, 1);
  }

  vi ans;
  int alive = n, x = 0, y = n - 1;
  while (alive > 2) {
    int r = a % alive, l = b % alive;
    int vx = ft.query(x + 1), vy = ft.query(y + 1);

    int i = ft.lower_bound(vx + r);
    if (i == n) {
      i = ft.lower_bound(r - (alive - vx));
    }
    x = i;

    if (vy - l >= 1) {
      i = ft.lower_bound(vy - l);
    } else {
      i = ft.lower_bound(alive - (l - vy));
    }
    y = i;
    
    if (x == y) {
      ans.pb(x + 1);
      ft.update(x, -1);
      alive--;

      int val = ft.query(x + 1);

      i = ft.lower_bound(val + 1);
      if (i == n) {
        i = ft.lower_bound(1);
      }
      x = i;

      if (val == 0) {
        i = ft.lower_bound(alive);
      } else {
        i = ft.lower_bound(val);
      }
      y = i;
      continue;
    }

    ft.update(x, -1);
    ft.update(y, -1);

    alive -= 2;

    vx = ft.query(x + 1);
    i = ft.lower_bound(vx + 1);
    if (i == n) {
      i = ft.lower_bound(1);
    }
    x = i;

    vy = ft.query(y + 1);
    if (vy == 0) {
      i = ft.lower_bound(alive);
    } else {
      i = ft.lower_bound(vy);
    }
    y = i;
  }

  while (1) {
    int i = ft.lower_bound(1);
    if (i == n) {
      break;
    }
    ft.update(i, -1);
    ans.pb(i + 1);
  }

  sort(ALL(ans));
  for (auto &x : ans) {
    cout << x << ' ';
  }
  cout << ENDL;

  return 0;
}