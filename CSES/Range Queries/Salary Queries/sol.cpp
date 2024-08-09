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
  int n; vi st, L, R;
  STree(int n) : st(1, NEUT), L(1, -1), R(1, -1), n(n) {}
  int comb(int x, int y) { return x + y; }
  int new_node(){st.pb(NEUT);L.pb(-1);R.pb(-1);return SZ(st)-1;}
  int query(int k, int s, int e, int a, int b) {
    if (k == -1 || e <= a || s >= b) return NEUT;
    if (a <= s && e <= b) return st[k];
    int m = s + (e - s) / 2;
    return comb(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
  }
  int upd(int k, int s, int e, int i, int v) {
    if (e <= i || s > i) return k;
    if (k == -1) {k = new_node();}
    if (s+1 == e) { st[k] += v; return k; }
    int m=s+(e-s)/2,le=L[k]==-1?0:st[L[k]],ri=R[k]==-1?0:st[R[k]];
    if (i < m) L[k] = upd(L[k],s,m,i,v), le = st[L[k]];
    else R[k] = upd(R[k],m,e,i,v), ri = st[R[k]];
    st[k] = comb(le, ri);
    return k;
  }
  int query(int a, int b) { return query(0, 0, n, a, b); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
};
 
signed main() {
  cin.tie(0)->sync_with_stdio(0);
 
  int n, q;
  cin >> n >> q;
  vi A(n);
  STree st(1e9 + 5);
  FOR (i, 0, n) {
    cin >> A[i];
    st.upd(A[i], 1);
  }
  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (op == '?') {
      cout << st.query(a, b + 1) << ENDL ;
      continue;
    }
    st.upd(A[--a], -1);
    st.upd(A[a] = b, 1);
  }
 
  return 0;
}