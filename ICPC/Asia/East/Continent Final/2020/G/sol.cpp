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

struct STree {
  #define lson (k<<1)+1
  #define rson (k<<1)+2
  #define lpart lson, s, (s+e)>>1
  #define rpart rson, (s+e)>>1, e
  #define NEUT 0LL

  int n;
  vector<ll> sum;
  vi flipped;
  vector<vi> cnt;
  vector<vector<ll>> lazy;

  STree(int n) : n(n), sum((n<<2)+5), flipped((n<<2)+5), cnt(2, vi((n<<2)+5)), lazy(2, vector<ll>((n<<2)+5)) {}

  void flip(int k) {
    swap(cnt[0][k], cnt[1][k]);
    swap(lazy[0][k], lazy[1][k]);
    flipped[k] ^= 1;
  }

  void apply_tag(int k, ll k0, ll k1) {
    sum[k] += k0 * cnt[0][k] + k1 * cnt[1][k];
    lazy[0][k] += k0, lazy[1][k] += k1;
  }

  void pull(int k) {
    sum[k] = sum[lson] + sum[rson];
    cnt[0][k] = cnt[0][lson] + cnt[0][rson];
    cnt[1][k] = cnt[1][lson] + cnt[1][rson];
  }

  void push(int k) {
    if (flipped[k]) flip(lson), flip(rson), flipped[k] ^= 1;
    apply_tag(lson, lazy[0][k], lazy[1][k]);
    apply_tag(rson, lazy[0][k], lazy[1][k]);
    lazy[0][k] = lazy[1][k] = 0;
  }

  void build(int k, int s, int e) {
    if (s + 1 == e) {
      cnt[0][k] = 1;
      return;
    }
    build(lpart), build(rpart);
    pull(k);
  }
  void build() { build(0, 0, n); }

  void flip(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s) return;
    if (a <= s && e <= b) {
      flip(k);
      return;
    }
    push(k);
    flip(lpart, a, b), flip(rpart, a, b);
    pull(k);
  }
  void flip(int a, int b) { flip(0, 0, n, a, b); }

  ll query(int k, int s, int e, int a, int b) {
    if (e <= a || b <= s) return NEUT;
    if (a <= s && e <= b) return sum[k];
    push(k);
    return query(lpart, a, b) + query(rpart, a, b);
  }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi nxt(n, -1);
  {
    vi lst(n, -1);
    FOR (i, 0, n) {
      int x;
      cin >> x;
      --x;
      if (~lst[x]) nxt[lst[x]] = i;
      lst[x] = i;
    }
    FOR (i, 0, n) if (!~nxt[i]) nxt[i] = n;
  }

  int q;
  cin >> q;
  vector<vector<pi>> Q(n);
  FOR (i, 0, q) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    Q[l].pb({r, i});
  }

  STree st(n);
  st.build();
  vector<ll> ans(q);
  ROF (l, n, 0) {
    st.flip(l, nxt[l]); 
    st.apply_tag(0, 0, 1);
    for (auto &[r, i] : Q[l]) ans[i] = st.query(l, r + 1);
  }

  for (auto &x : ans) cout << x << ENDL;

  return 0;
}