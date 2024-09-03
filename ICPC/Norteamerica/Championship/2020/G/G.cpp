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
constexpr int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
constexpr int maxn = 500;
int n, m;
char a[maxn][maxn];
int gn[maxn*maxn];
int in_deg[maxn*maxn];
int encode(int i, int j){return i*m+j;}
pi decode(int x){return {x / m, x % m};}
int valid(int i, int j){return i!=-1&&i!=n&&j!=-1&&j!=m;}
void add_edge(int i, int j, int k) {
  int ii = i + di[k], jj = j + dj[k];
  if(valid(ii,jj)&&a[ii][jj]!='#'&&a[ii][jj]!='.') {
    int u = encode(i, j), v = encode(ii, jj);
    gn[u] = v, in_deg[v]++;
  }
}
int nodes_gc = 0;
int new_id[maxn*maxn];
int cycle[maxn*maxn];
int gc[maxn*maxn];
vi rgc[maxn*maxn];
set<int> spots_gn[maxn*maxn];
set<int> spots_gc[maxn*maxn];
void compress() {
  queue<int> q;
  FOR(i,0,n)FOR(j,0,m){
    int u = encode(i, j);
    if(!in_deg[u])q.push(u);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if(gn[u]!=-1)if(!--in_deg[gn[u]])q.push(gn[u]);
  }
  FOR(u,0,n*m){
    if(!in_deg[u]) {
      if(cycle[u])continue;
      new_id[u] = nodes_gc++;
      continue;
    }
    int x = u;
    new_id[u]=nodes_gc,in_deg[u]=0,cycle[u]=1,x=gn[u];
    while(x!=u)new_id[x]=nodes_gc,in_deg[x]=0,cycle[x]=1,x=gn[x];
    ++nodes_gc;
  }
  FOR(u,0,n*m){
    if(!cycle[u]&&gn[u]!=-1)gc[new_id[u]]=new_id[gn[u]],rgc[new_id[gn[u]]].pb(new_id[u]);
    for(auto &v:spots_gn[u])spots_gc[new_id[u]].insert(new_id[v]);
  }
}
int cnt_spot[maxn*maxn];
int vis[maxn*maxn];
int curr_spots;
int solve(int u) {
  for(auto &v:spots_gc[u])if(++cnt_spot[v]==1)curr_spots++;
  int ans=curr_spots;
  for(auto &v:rgc[u])ans=max(ans,solve(v));
  for(auto &v:spots_gc[u])if(!--cnt_spot[v])curr_spots--;
  return ans;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  FOR(i,0,n)FOR(j,0,m)cin>>a[i][j];
  memset(gn,-1,sizeof gn);
  memset(gc,-1,sizeof gc);
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (a[i][j] == '^') add_edge(i,j,0);
      else if (a[i][j] == '>') add_edge(i,j,1);
      else if (a[i][j] == 'v') add_edge(i,j,2);
      else if (a[i][j] == '<') add_edge(i,j,3);
      else continue;
      int u = encode(i, j);
      FOR (k, 0, 4) {
        int ii = i + di[k], jj = j + dj[k];
        if (valid(ii, jj) && a[ii][jj] == '#') {
          int v = encode(ii, jj);
          spots_gn[u].insert(v);
        }
      }
    }
  }
  compress();
  int ans=0;
  FOR(i,0,n)FOR(j,0,m)if(a[i][j]!='.'&&a[i][j]!='#'){
    int l_r=encode(i,j),r=new_id[l_r];
    if (gc[r]!=-1||vis[r])continue;
    vis[r]=1;
    curr_spots=0;
    ans=max(ans,solve(r));
  }
  cout<<ans<<ENDL;

  return 0;
}