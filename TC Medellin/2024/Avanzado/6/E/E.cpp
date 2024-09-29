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

ll be(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  ll l = 1, r = 1e12;
  while (l < r) {
    ll m = (l + r) >> 1;
    cout << "? " << m << endl;
    int k;
    cin >> k;
    if (k > n) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  ll d0 = l;

  l = 1, r = 1e15;
  while (l < r) {
    ll m = (l + r) >> 1;
    cout << "? " << m << endl;
    int k;
    cin >> k;
    if (k > n + 1) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  ll d1 = l - d0;

  ll b = 2;
  while (be(b, n + 1) - be(b, n) != d1) {
    b++;
  }

  cout << "! " << be(b, n) - d0 << ' ' << b << endl;

  return 0;
}