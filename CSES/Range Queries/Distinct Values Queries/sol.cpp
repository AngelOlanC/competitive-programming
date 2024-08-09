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

constexpr int maxn = 2e5 + 5;

int ans = 0;
int c[maxn];
int a[maxn];

void add(int i) { ans += ++c[a[i]] == 1; }
void del(int i) { ans -= --c[a[i]] == 0; }

vi mosAlgo(vector<pi> Q) {
  int L = 0, R = 0, blk = 500;  // IMPORTANT!! blk ~= N/sqrt(Q)
  vi s(SZ(Q)), res = s;
#define K(x) pi(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    pi q = Q[qi];
    while (L > q.first) add(--L);
    while (R < q.second) add(R++);
    while (L < q.first) del(L++);
    while (R > q.second) del(--R);
    res[qi] = ans;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vi ind;
  FOR (i, 0, n) {
    cin >> a[i];
    ind.pb(a[i]);
  }
  sort(ALL(ind));
  ind.erase(unique(ALL(ind)), ind.end());
  FOR (i, 0, n) a[i] = lower_bound(ALL(ind), a[i]) - ind.begin();
  vector<pi> Q(q);
  for (auto &[l, r] : Q) {
    cin >> l >> r;
    --l;
  }
  vi ans = mosAlgo(Q);
  for (auto &ansi : ans) cout << ansi << ENDL;
  return 0;
}