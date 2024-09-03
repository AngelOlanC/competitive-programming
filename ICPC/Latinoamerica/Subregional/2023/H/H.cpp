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

#define NEUT 0
#define op(a, b) (max(a, b))
const int SZ = 1e9 + 5;
template <class T>
struct node {
  T val = NEUT;
  node<T>* c[2];
  node() { c[0] = c[1] = NULL; }
  void upd(int ind, T v, int L = 0, int R = SZ - 1) {
    if (L == ind && R == ind) {
      val = op(val, v);
      return;
    }
    int M = (L + R) / 2;
    if (ind <= M) {
      if (!c[0])
        c[0] = new node();
      c[0]->upd(ind, v, L, M);
    } else {
      if (!c[1])
        c[1] = new node();
      c[1]->upd(ind, v, M + 1, R);
    }
    val = NEUT;
    for (int i = 0; i < 2; i++)
      if (c[i])
        val = op(val, c[i]->val);
  }
  T query(int lo, int hi, int L = 0, int R = SZ - 1) {  // [l, r]
    if (hi < L || R < lo) return NEUT;
    if (lo <= L && R <= hi) return val;
    int M = (L + R) / 2;
    T res = NEUT;
    if (c[0]) res = op(res, c[0]->query(lo, hi, L, M));
    if (c[1]) res = op(res, c[1]->query(lo, hi, M + 1, R));
    return res;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  int l[n], r[n], c[n], mxr = 0;
  FOR (i, 0, n) {
    cin >> l[i] >> r[i] >> c[i];
    mxr = max(mxr, r[i]);
  }

  int p[n];
  iota(p, p + n, 0);
  sort(p, p + n, [&](int i, int j) { 
    return l[i] < l[j] || (l[i] == l[j] && r[i] < r[j]); 
  });

  node<ll> stDP, stMX;
  mxr++;
  stMX.upd(mxr, 1ll * mxr * s); 

  ll dp[n + 1];
  dp[n] = 0;
  ROF (i, n, 0) {
    ll incomplete = stMX.query(l[p[i]], r[p[i]]);
    incomplete -= 1ll * l[p[i]] * s;
    incomplete -= c[p[i]];

    ll complete = 1ll * (r[p[i]] - l[p[i]] + 1) * s;
    complete -= c[p[i]];
    complete += stDP.query(r[p[i]] + 1, SZ - 1);

    dp[i] = max({0LL, complete, incomplete});

    stDP.upd(l[p[i]], dp[i]);
    stMX.upd(l[p[i]], 1ll * l[p[i]] * s + dp[i]);
  }
  cout << *max_element(dp, dp + n) << ENDL;

  return 0;
}
