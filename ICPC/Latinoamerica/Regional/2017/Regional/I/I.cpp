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

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

constexpr int maxn = 1e5 + 5, maxlog = 25;

int n, m;
vector<pi> g[maxn];
int d[maxn], jmp[maxn][maxlog], mx[maxn][maxlog];
void dfs(int u, int p = -1, int lw = 0) {
  jmp[u][0]=p;
  mx[u][0]=lw;
  for (auto &[v,w]:g[u])if(v!=p)d[v]=d[u]+1,dfs(v,u,w);
}
void build() {
  dfs(0);
  for(int i=1;i<maxlog;i++)for(int u=0;u<n;u++)if(jmp[u][i-1]!=-1) {
    jmp[u][i]=jmp[jmp[u][i-1]][i-1];
    mx[u][i]=max(mx[u][i-1],mx[jmp[u][i-1]][i-1]);
  }
}
int mx_in_path(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  int dist = d[u] - d[v], val = 0;
  for(int i=maxlog-1;i>=0;i--)if((dist>>i)&1)val=max(val,mx[u][i]),u=jmp[u][i];
  if(u==v)return val;
  for(int i=maxlog-1;i>=0;i--)if(jmp[u][i]!=jmp[v][i])val=max({val,mx[u][i],mx[v][i]}),u=jmp[u][i],v=jmp[v][i];
  val = max({val, mx[u][0], mx[v][0]});
  return val;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;
  vector<array<int, 3>> e(m);
  map<pi, int> mp;
  for (auto &[w, u, v] : e) {
    cin >> u >> v >> w;
    --u, --v;
    mp[{u, v}] = mp[{v, u}] = w;
  }
  sort(ALL(e));
  int n2 = n;
  DSU dsu;
  dsu.init(n);
  ll mst = 0;
  for (auto &[w, u, v]:e)if(dsu.get(u)!=dsu.get(v)){
    mst += w;
    dsu.join(u, v);
    g[u].pb({v, w}), g[v].pb({u, w});
    if (--n2 == 1) break;
  }
  build();
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    cout << mst + mp[{u, v}] - mx_in_path(u, v) << ENDL;
  }

  return 0;
}