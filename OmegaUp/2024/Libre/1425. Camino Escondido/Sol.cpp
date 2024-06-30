#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define nl "\n"
#define mset(x,y) memset(x, y, sizeof(x))
#define read(s) getline(cin>>ws,s)
#define redondear(x) fixed<<setprecision(x)
using namespace std;
void DBG(){	cerr<<")\n";}
template<class H, class... T > 
void DBG( H h, T... t){cerr << h;if( sizeof...(t))cerr<<", ";DBG(t...);}
#define dbg(...) cerr <<" values[ "<< #__VA_ARGS__ << " ] = ( ", DBG(__VA_ARGS__)
template <typename T>
ostream & operator <<(ostream &os, const vector < T >&v){os << "[";
for(int c = 0 ; c<sz(v); c++){if(c > 0) os<<","; os<<v[c];}
return os <<"] ";}
template <typename T>
ostream & operator <<(ostream &os, const set < T >&v){os << "[";
for(int c : v){os<<","; os<<c;}
return os <<"] ";}
template<class T1, class T2>
ostream & operator <<(ostream &os, const pair < T1, T2>&sol ){
os<<"("<<sol.fi<<", "<<sol.se;return os <<") ";}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef short int sint;
const int nega= -1;
const double pi= 3.141592;
const ll di4[4]={0,1,0,-1}, dj4[4]={1,0,-1,0};
const ll diagi[4]={1,1,-1,-1}, diagj[4]={1,-1,-1,1};
const int di8[8]={0,1,1,1,0,-1,-1,-1}, dj8[8]={1,1,0,-1,-1,-1,0,1};
const int INF= 1e9;
const ll M= 1e9 + 7;
#define MAXN 21
const int cabaX[8]={-2,-2,-1,1,2,2,1,-1}, cabaY[8]={-1,1,2,2,1,-1,-2,-2};
vector<vector<int>> tab(MAXN,vector<int>(MAXN,0));
vector<vector<set<int>>> seg(MAXN,vector<set<int>>(MAXN));
vector<vector<bool>> vis(MAXN,vector<bool>(MAXN,false));
int n;
bool es(int x, int y){
	return x>=1&&x<=n&&y>=1&&y<=n&&!vis[x][y];
}
void bfs(int x, int y){
	queue<array<int,3>> cola;
	cola.push({x,y,0});
	vis[x][y]= true;
	tab[x][y]++;
	seg[x][y].insert(0);
	while(!cola.empty()){
		auto ac= cola.front(); cola.pop();
		int x= ac[0],y= ac[1],s= ac[2];
		for(int i=0;i<8;i++){
			if(es(x+cabaX[i],y+cabaY[i])){
				vis[x+cabaX[i]][y+cabaY[i]]= true;
				tab[x+cabaX[i]][y+cabaY[i]]++;
				seg[x+cabaX[i]][y+cabaY[i]].insert(s+1);
				cola.push({x+cabaX[i],y+cabaY[i],s+1});
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m; cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y; cin>>x>>y;
		bfs(x,y);
		vis= vector<vector<bool>>(MAXN, vector<bool>(MAXN,false));
	}
	int ans= INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(tab[i][j]==m){
				//dbg(i,j,seg[i][j], tab[i][j], *prev(seg[i][j].end(),1));
				auto it= seg[i][j].end(); it--;
				//cout<<*it<<" ";
				ans= min(ans,*it);
			}
			//cout<<tab[i][j]<<" ";
		}
		//cout<<nl;
	}
	//cout<<nl;
	cout<<(ans==INF ? nega : ans);
    return 0;
}