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

constexpr int maxx = 1e6 + 5;

int n;
int a[maxx];
int cnt[maxx];

void add(int i, int &impares) {
  if (cnt[a[i]] % 2) impares--;
  cnt[a[i]]++;
  if (cnt[a[i]] % 2) impares++;
}
void del(int i, int &impares) {
  if (cnt[a[i]] % 2) impares--;
  cnt[a[i]]--;
  if (cnt[a[i]] % 2) impares++;
}
int calc(int &impares){
  return impares != 0;
}

vi mosAlgo(vector<pi> Q) {
  int L = 0, R = 0, blk = 350;
  int impares = 0;
  vi s(SZ(Q)), res = s;
#define K(x) pi(x.first/blk,x.second^-(x.first/blk&1))
  iota(ALL(s), 0);
  sort(ALL(s),[&](int s,int t){return K(Q[s])<K(Q[t]);});
  for (int qi : s) {
    pi q = Q[qi];
    while (L > q.first) add(--L, impares);
    while (R < q.second) add(R++, impares);
    while (L < q.first) del(L++, impares);
    while (R > q.second) del(--R, impares);
    res[qi] = calc(impares);
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int q;
    cin >> n >> q;
    FOR (i, 0, n) cin >> a[i];
    vector<pi> Q(q);
    for (auto &[l, r] : Q) {
      cin >> l >> r;
      --l;
    }
    vi ans = mosAlgo(Q);
    for (auto &x : ans) cout << (x ? "NO" : "YES") << ENDL;
    FOR (i, 0, n) cnt[a[i]] = 0;
  }

  return 0;
}