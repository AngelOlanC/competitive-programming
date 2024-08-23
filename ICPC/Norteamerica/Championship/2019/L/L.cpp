#include <bits/stdc++.h>
using namespace std;
// Puro pinche BRO... CSM y CSM compa
constexpr int maxn=500+5;
constexpr int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int n, m;
char a[maxn][maxn];
pair<int,int> memo[maxn][maxn][4];
int encode(int i,int j){return i*m+j;}
pair<int,int> decode(int v){return {v/m,v%m};}
pair<int,int> dp(int i,int j,int d) {
  if(i==-1||i==n||j==-1||j==m){
    d=(d+2)%4;
    return dp(i+di[d],j+dj[d],d);
  }
  if(a[i][j]=='#'||a[i][j]=='V'||a[i][j]=='H')return {encode(i,j),0};
  if(a[i][j]=='.')return dp(i+di[d],j+dj[d],d);
  if(memo[i][j][d].first!=-1)return memo[i][j][d];
  if(a[i][j]=='\\')d=3-d;
  else d^=1;
  auto [x,y]=dp(i+di[d],j+dj[d],d);
  return {x,y+1};
}
vector<pair<int,int>> g[maxn*maxn];
vector<vector<int>> comp;
int valid[maxn*maxn][2];
int vis[maxn*maxn];
int c[maxn*maxn];
int dfs(int u){
  vis[u]=1;
  comp.back().push_back(u);
  for(auto &[v,w]:g[u]){
    int cv=c[u]^w;
    if(vis[v]&&c[v]!=cv)return false;
    c[v]=cv;
    if(!vis[v]&&!dfs(v))return false;
  }
  return true;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i=0;i<n;++i)for(int j=0;j<m;++j){
    cin>>a[i][j];
    for(int k=0;k<4;++k)memo[i][j][k]={-1,-1};
    int x=encode(i,j);
    valid[x][0]=valid[x][1]=1;
  }
  for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(a[i][j]=='V'||a[i][j]=='H'){
    for(int d=0;d<=1;++d){
      auto [x0,y0]=dp(i+di[d],j+dj[d],d);
      auto [i0,j0]=decode(x0);
      auto [x1,y1]=dp(i+di[d+2],j+dj[d+2],d+2);
      auto [i1,j1]=decode(x1);
      if(a[i0][j0]=='#'||a[i1][j1]=='#'){
        valid[encode(i,j)][d]=0;
        continue;
      }
      int u=encode(i,j),v=encode(i0,j0);
      g[u].push_back({v,y0%2}),g[v].push_back({u,y0%2});
      v=encode(i1,j1);
      g[u].push_back({v,y1%2}),g[v].push_back({u,y1%2});
    }
  }
  for(int u=0;u<n*m;++u){
    auto [i,j]=decode(u);
    if((a[i][j]=='V'||a[i][j]=='H')&&!vis[u]){
      comp.push_back({});
      if (!dfs(u)) {
        cout<<-1<<'\n';
        return 0;
      }
    } 
  }
  int ans=0;
  for (auto &cmp:comp){
    int add=1e9,bad=0;
    bool good=1;
    for(auto &u:cmp){
      good&=valid[u][c[u]];
      auto [i,j]=decode(u);
      bad+=(a[i][j]=='H')!=c[u];
    }
    if(good)add=bad;
    bad=0,good=1;
    for(auto &u:cmp){
      c[u]=!c[u];
      good&=valid[u][c[u]];
      auto [i,j]=decode(u);
      bad+=(a[i][j]=='H')!=c[u];
    }
    if(good)add=min(add,bad);
    if(add==1e9){
      cout<<-1<<'\n';
      return 0;
    }
    ans+=add;
  }
  cout<<ans<<'\n';
  return 0;
}