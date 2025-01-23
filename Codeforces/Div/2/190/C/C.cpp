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

constexpr int maxn = 1e5 +5 ;

int n;
bool tk[maxn];
int szt[maxn], fat[maxn], ans[maxn];
vi g[maxn];
int calcsz(int u, int f){
	szt[u]=1;
	for(auto v:g[u])if(v!=f&&!tk[v])szt[u]+=calcsz(v,u);
	return szt[u];
}
void cdfs(int x=0, int f=-1, int c = 0, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto v:g[x])if(!tk[v]&&szt[v]*2>=sz){
		szt[x]=0;cdfs(v,f,c,sz);return;
	}
	ans[x]=c;tk[x]=true;fat[x]=f;
	for(auto v:g[x])if(!tk[v])cdfs(v,x,c+1);
}
void decompose(){memset(tk,false,sizeof(tk));cdfs();}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
  }
  decompose();
  FOR (i, 0, n) cout << char('A' + ans[i]) << " \n"[i == n - 1];

  return 0;
}