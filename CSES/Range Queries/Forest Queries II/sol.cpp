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
  int n, m;
  vector<vi> st;
  STree(int n, int m) : st(2*n, vi(2*m,NEUT)), n(n), m(m) {}
  int comb(int x,int y){return x+y;}
  void build(vector<vi>& a) {
    FOR(i,0,n)FOR(j,0,m)
      st[i+n][j+m]=a[i][j];
    FOR(i,0,n)for(int j=m-1;j;--j)
      st[i+n][j]=comb(st[i+n][j<<1],st[i+n][j<<1|1]);
    for(int i=n-1;i;--i)FOR(j,0,2*m)
      st[i][j]=comb(st[i<<1][j],st[i<<1|1][j]);
  }
  void upd(int x, int y, int v){
    st[x+n][y+m]=v;
    for(int j=y+m;j>1;j>>=1)st[x+n][j>>1]=comb(st[x+n][j],st[x+n][j^1]);
    for(int i=x+n;i>1;i>>=1)for(int j=y+m;j;j>>=1)
      st[i>>1][j]=comb(st[i][j],st[i^1][j]);
  }
  int query(int x0, int y0, int x1, int y1){
    int r=0;
    for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
      int t[4],q=0;
      if(i0&1)t[q++]=i0++;
      if(i1&1)t[q++]=--i1;
      FOR(k,0,q)for(int j0=y0+m,j1=y1+m;j0<j1;j0>>=1,j1>>=1){
        if(j0&1)r=comb(r,st[t[k]][j0++]);
        if(j1&1)r=comb(r,st[t[k]][--j1]);
      }
    }
    return r;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vector<vi> a(n, vi(n));
  FOR (i, 0, n) FOR (j, 0, n) {
    char c;
    cin >> c;
    a[i][j]= c == '*';
  }
  
  STree st(n, n);
  st.build(a);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i, j;
      cin >> i >> j;
      --i, --j;
      st.upd(i,j,a[i][j] = !a[i][j]);
      continue;
    }
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << st.query(y1 - 1, x1 - 1, y2, x2) << ENDL;
  }

  return 0;
}