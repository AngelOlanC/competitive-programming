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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using query = array<int, 3>;

constexpr int maxn = 3e5 + 5;

int n, q;
int a[maxn];
int cnt[maxn];

void add(int idx) {
  ++cnt[a[idx]];
}
void del(int idx) {
  --cnt[a[idx]];
}
int calc(query& q){
  // cout << "answering " << q[0] << ' ' << q[1] << ' ' << q[2] << ENDL;
  int mn = 1e9, dif = q[1] - q[0];
  FOR (it, 0, 90) {
    int i = uniform_int_distribution<int>(q[0], q[1])(rng);
    // cout << i << ENDL;
    if (cnt[a[i]] * q[2] > dif) {
      mn = min(mn, a[i]);
    } 
  }
  return mn != 1e9 ? mn : -1;
}

vi mosAlgo(vector<query>& Q) {
  int L = 0, R = 0, blk = 700;  // IMPORTANT!! blk ~= N/sqrt(Q)
  vi s(SZ(Q)), res = s;
#define K(x) pi(x[0] / blk, x[1] ^ -(x[0] / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    query q = Q[qi];
    // cout << "answering " << q[0] + 1 << ' ' << q[1] << ENDL;
    while (L > q[0]) add(--L);
    while (R < q[1]) add(R++);
    while (L < q[0]) del(L++);
    while (R > q[1]) del(--R);
    res[qi] = calc(Q[qi]);
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> q;
  FOR (i, 0, n) cin >> a[i];

  vector<query> Q(q);
  for (auto &[l, r, k] : Q) {
    cin >> l >> r >> k;
    --l;
  }
  
  for (auto &x : mosAlgo(Q)) cout << x << ENDL;

  return 0;
}