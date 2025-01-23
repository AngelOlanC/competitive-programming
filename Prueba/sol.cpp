#include <bits/stdc++.h>
using namespace std;

#define pb 					push_back
#define mp 					make_pair
#define eb                  emplace_back
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define deb(x)    			cout << #x << " = " << x << '\n';
#define deb2(x, y)			cout << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define deb3(x,y,z)			cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << '\n';
#define FOR(x, n) 			for(int x = 0; x < (int)n; x++)
#define FOR1(x, n) 			for(int x = 1; x <= (int)n; x++)
#define FORR(x, n) 			for(int x = n-1; x >= 0; x--)
#define FORR1(x, n) 		for(int x = n; x >= 1; x--)
#define INF                 1 << 28
#define MOD                 1000000007
#define MAXN                1000005

typedef long long 		   		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>			ii;
typedef tuple<int, int, int>    iii;
typedef vector<int> 			vi;
typedef vector<ii> 				vii;

vector<int> maxx;
vector<vector<iii>> graph;

void dfs(int u, int l, int r){
	if(r - l + 1 <= maxx[u])
		return;
	maxx[u] = r - l + 1;
	
	FOR(i, graph[u].size()){
		int v = get<0>(graph[u][i]), l1 = get<1>(graph[u][i]), r1 = get<2>(graph[u][i]);
		
		int l2 = max(l, l1), r2 = min(r, r1); //intersecciones
		
		if(l2 > r2) //si no hay interseccion
			continue;
		dfs(v, l2, r2);
	}
}

void dfs2(int u, int l, int r){
	if(r - l + 1 <= maxx[u])
		return;
	
	FOR(i, graph[u].size()){
		int v = get<0>(graph[u][i]), l1 = get<1>(graph[u][i]), r1 = get<2>(graph[u][i]);
		
		int l2 = max(l, l1), r2 = min(r, r1); //intersecciones
		
		if(l2 > r2) //si no hay interseccion
			continue;
		else
			maxx[u] = max(maxx[u], r2 - l2 + 1);
		dfs(v, l2, r2);
	}
}

int main(){
	ios_base :: sync_with_stdio(0); cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	graph.assign(n, vector<iii>());
	maxx.assign(n, 0);
	
	FOR(i, m){
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		
		if(u != v){
			graph[u - 1].eb(v - 1, l, r);
			graph[v - 1].eb(u - 1, l, r);
		}
	}
	
	dfs(0, 1, 1000000);
	int r1 = maxx[n - 1];
	
	maxx.assign(n, 0);
	
	dfs2(n - 1, 1, 1000000);
	int r2 = maxx[0];
	
	if(max(r1, r2) == 0)
		cout << "Oh, vamos!\n";
	else
		cout << max(r1, r2) << '\n';
}