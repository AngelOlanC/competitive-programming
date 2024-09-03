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
constexpr int maxn = 5000 + 5, max_k = 600 + 5;
int n;
int a[maxn];
vi g[maxn];
int memo[maxn][max_k];
int gcdd[max_k][max_k];
int dp(int u,int k,int p) {
  int &ans=memo[u][k];
  if(ans!=-1)return memo[u][k];
  ans=a[u]==k?0:k;
  for (auto &v:g[u])if(v!=p){
    int mn=1e9;
    FOR(kk,2,max_k)if(gcdd[k][kk]!=1)mn=min(mn,dp(v,kk,u));
    ans+=mn;
  }
  return ans;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(memo,-1,sizeof memo);
  FOR(x,2,max_k)FOR(y,x,max_k)gcdd[x][y]=gcdd[y][x]=gcd(x,y);
  cin>>n;
  FOR(i,0,n)cin>>a[i];
  FOR(i,1,n){
    int u,v;
    cin>>u>>v;
    --u,--v;
    g[u].pb(v),g[v].pb(u);
  }
  int ans=1e9;
  FOR(k,2,max_k)ans=min(ans,dp(0,k,-1));
  cout<<ans<<ENDL;
  return 0;
}