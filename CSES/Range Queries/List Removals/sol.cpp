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

#define NEUT 0
struct STree {
  int n; vi st;
  STree(int n) : st(4 * n + 5, NEUT), n(n) {}
  int comb(int x, int y) { return x + y; }
  void init(int k, int s, int e, vi& a) {
    if (s + 1 == e) { st[k] = a[s]; return; }
    int m = (s+e)/2;
    init(2*k+1, s, m, a); init(2*k+2, m, e, a);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  int query(int k, int s, int e, int i) {
    if (s + 1 == e) return s;
    int m = (s+e)/2;
    return i <= st[2*k+1] ? query(2*k+1,s,m,i):query(2*k+2,m,e,i-st[2*k+1]);
  }
  void upd(int k, int s, int e, int i) {
    if (e <= i || s > i) return;
    if (s+1 == e) { st[k] = 0; return; }
    int m = (s+e)/2;
    upd(2*k+1,s,m,i); upd(2*k+2,m,e,i);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  int query(int i) { return query(0, 0, n, i); }
  void upd(int i) { upd(0, 0, n, i); }
  void init(vi a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];
  STree st(n); st.init(vi(n, 1));
  FOR (i, 0, n) {
    int p;
    cin >> p;
    int j = st.query(p);
    cout << a[j] << " \n"[i == n - 1];
    st.upd(j);
  }

  return 0;
}