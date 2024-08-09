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

template<class T, int SZ> struct pseg {
	static const int LIMIT = 1e5; // adjust
	int l[LIMIT], r[LIMIT], nex = 0;
	T val[LIMIT], lazy[LIMIT];
	//// HELPER
	int copy(int cur) {
		int x = nex++;
		val[x]=val[cur],l[x]=l[cur],r[x]=r[cur],lazy[x]=lazy[cur];
		return x;
	}
	T comb(T a, T b) { return a + b; }
	void pull(int x) { val[x] = comb(val[l[x]],val[r[x]]); } 
	void push(int cur, int L, int R) { 
		if (!lazy[cur]) return;
    val[cur] += 1ll * (R - L + 1) * lazy[cur];
		if (L != R) {
			l[cur] = copy(l[cur]);
			lazy[l[cur]] += lazy[cur];
			r[cur] = copy(r[cur]);
			lazy[r[cur]] += lazy[cur];
		}
		lazy[cur] = 0;
	}
	//// MAIN FUNCTIONS
	T query(int cur, int lo, int hi, int L, int R) {  
    push(cur, L, R);
		if (R < lo || hi < L) return 0;
		if (lo <= L && R <= hi) return val[cur];

		int M = (L+R)/2;    
    
    return comb(query(l[cur],lo,hi,L,M),
    query(r[cur],lo,hi,M+1,R));
	}
	int upd(int cur, int lo, int hi, T v, int L, int R) {
    if (R < lo || hi < L) return cur;
		int x = copy(cur);
		if (lo <= L && R <= hi) { 
      push(x, L, R);
			lazy[x] += v;
		  push(x, L, R);
			return x; 
		}
		push(x, L, R);
		int M = (L+R)/2;
		l[x] = upd(l[x],lo,hi,v,L,M);
		r[x] = upd(r[x],lo,hi,v,M+1,R);
		pull(x); return x;
	}
	int build(vector<T>& arr, int L, int R) {
		int cur = nex++;
		if (L == R) {
			if (L < SZ(arr)) val[cur] = arr[L];
			return cur;
		}
		int M = (L+R)/2;
		l[cur] = build(arr,L,M), r[cur] = build(arr,M+1,R);
		pull(cur); return cur;
	}
	//// PUBLIC
	vi loc;
	void upd(int lo, int hi, T v) { 
		loc.pb(upd(loc.back(),lo,hi,v,0,SZ-1)); }
	T query(int ti, int lo, int hi) { 
		return query(loc[ti],lo,hi,0,SZ-1); }
	void build(vector<T>& arr) { loc.pb(build(arr,0,SZ-1)); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vi a = {1, 2, 3, 4, 5};
  pseg<int, 5> st;
  st.build(a);
  cout << st.query(0, 0, 5) << ENDL;
  
  st.upd(0, 2, 1);
  cout << st.query(1, 0, 5) << ENDL;
  cout << st.query(0, 0, 2) << ENDL;
  cout << st.query(0, 0, 1) << ENDL;
  cout << st.query(1, 0, 1) << ENDL;
  cout << st.query(1, 2, 4) << ENDL;


  return 0;
}