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

constexpr int maxn = 1e5 + 5, max_xor = 1 << 25;

int n, m, k;
int a[maxn];
int p[maxn];
int c[max_xor];
ll ans;

void add(int idx) {
  // cout << "add " << idx << ENDL;
  ans += c[k ^ p[idx]];
  ++c[p[idx]];
}
void del(int idx) {
  // cout << "delete " << idx << ENDL;
  --c[p[idx]];
  ans -= c[k ^ p[idx]];
}

vector<ll> mosAlgo(vector<pi> Q) {
  int L = 0, R = 0, blk = 350;  // IMPORTANT!! blk ~= N/sqrt(Q)
  vi s(SZ(Q));
  vector<ll> res(SZ(Q));
#define K(x) pi(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    pi q = Q[qi];
    // cout << "answer " << q.first + 1 << ' ' << q.second << ENDL;
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

  cin >> n >> m >> k;
  FOR (i, 0, n) cin >> a[i];
  FOR (i, 1, n + 1) p[i] = p[i - 1] ^ a[i - 1];

  vector<pi> Q(m);
  for (auto &[l, r] : Q) {
    cin >> l >> r;
    --l, ++r;
  }

  for (auto &x : mosAlgo(Q)) cout << x << ENDL;

  return 0;
}