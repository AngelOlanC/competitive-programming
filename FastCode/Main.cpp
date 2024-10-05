#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define nl "\n"
#define mset(x,y) memset(x, y, sizeof(x))
#define read(s) getline(cin>>ws,s)
#define vi vector<int>
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
using namespace std;
#define redondear(x) fixed<<setprecision(x)
void DBG(){    cerr<<")\n";}
template<class H, class... T > 
void DBG( H h, T... t){cerr << h;if( sizeof...(t))cerr<<", ";DBG(t...);}
#define dbg(...) cerr <<" values[ "<< #__VA_ARGS__ << " ] = ( ", DBG(__VA_ARGS__)
template <typename T>
ostream & operator <<(ostream &os, const vector < T >&v){os << "[";
for(int c = 0 ; c<v.size(); c++){if(c > 0) os<<","; os<<v[c];}
return os <<"] ";}
template <typename T>
ostream & operator <<(ostream &os, const set < T >&v){os << "[";
for(int c : v){os<<","; os<<c;}
return os <<"] ";}
template<class T1, class T2>
ostream & operator <<(ostream &os, const pair < T1, T2>&sol ){
os<<"("<<sol.fi<<", "<<sol.se;return os <<") ";}//*/
//typedef short int sint;
//const double pi= acos(-1);
//const int dx4[4]={0,1,0,-1}, dy4[4]={-1,0,1,0};
//const int diagi[4]={1,1,-1,-1}, diagj[4]={1,-1,-1,1};
//const int dx8[8]={0,1,1,1,0,-1,-1,-1}, dy8[8]={1,1,0,-1,-1,-1,0,1};
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int nega= -1;
const ll INF= 1e9;
const ll M= 1e9 + 7;
#define MAXN 105
pair<int,vi> kuhn(vector<vi>& g, int m) {
  vi vis, btoa(m, -1);
  auto dfs = [&](auto self, int j) -> bool {
    if (btoa[j] == -1) return 1;
    vis[j] = 1;
    int di = btoa[j];
    for (int e : g[di]) if (!vis[e] && self(self, e)) {
      btoa[e] = di;
      return 1;
    }
    return 0;  
  };
  FOR (i, 0, sz(g)) {
    vis.assign(sz(btoa), 0);
    for (int j : g[i]) if (dfs(dfs, j)) {
      btoa[j] = i;
      break;
    }
  }
  return {sz(btoa) - (int)count(all(btoa), -1), btoa};
}
bool myfunc(tuple<string,int,vector<string>> a, tuple<string,int,vector<string>> b){
    auto [s1,e1,a1]= a;
    auto [s2,e2,a2]= b;
    if(e1 == e2){
        return s1 < s2;
    }
    return e1 > e2;
}
int n,m;
map<string,int> rival; vector<string> yo;
vector<tuple<string,int,vector<string>>> acomodo;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string r; cin>>r;
        rival[r]= i;
    }
    acomodo.assign(n,{});
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int e,c; cin>>e>>c; vector<string> aux;
        while(c--){
            string r; cin>>r;
            aux.pb(r);
        }
        acomodo[i]= {s,e,aux};
    }
    sort(all(acomodo),myfunc);
    vector<vi> g(n);
    for(int i=0;i<n;i++){
        auto [s,e,aux]= acomodo[i];
        yo.pb(s);
        for(string j : aux) g[i].pb(rival[j]);
    }
    auto [cnt,btoa]= kuhn(g,m);
    vector<string> ans; vector<bool> usados(n,false);
    for(int i=0;i<m;i++){
        if(btoa[i] != -1){
            ans.pb(yo[btoa[i]]);
            usados[btoa[i]]= true;
        }
    }
    if(cnt!=m){
        for(int i=0;i<n;i++){
            if(!usados[i]){
                ans.pb(yo[i]);
                if(sz(ans) == m) break;
            }
        }
    }
    sort(all(ans));
    for(string s : ans) cout<<s<<nl;
    return 0;
}