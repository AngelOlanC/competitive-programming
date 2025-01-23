#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define Aint(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int INF = 1e6;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int m, n, l; cin >> m >> n >> l;

  vector<int> members(l);
  FOR(i, 0, l){
    int city; cin >> city;
    members[i] = city - 1;
  }

  vector<vector<int>> regions(m);
  vector<vector<int>> cities(n);
  FOR(k, 0, m){
    int i; cin >> i;
    FOR(j, 0, i){
      int city; cin >> city;
      regions[k].pb(city - 1);
      cities[city - 1].pb(k);
    }
  }

  vector<vector<int>> adj(m, vector<int>(m, INF));
  FOR(i, 0, m){
    // cout << "Region " << i << ENDL;
    adj[i][i] = 0;
    FOR(j, 0, SZ(regions[i])){
      // cout << regions[i][j] << " - " << regions[i][(j + 1) % SZ(regions[i])] << ENDL;
      FOR(k, i + 1, m){
        // cout << "    Region " << k << ENDL;
        // cout << k << '\n';
        FOR(l, 0, SZ(regions[k])){
          // cout << "    " << regions[k][l] << " - " << regions[k][(l + 1) % SZ(regions[k])] << ENDL;
          if((regions[i][j] == regions[k][(l + 1) % SZ(regions[k])] && regions[i][(j + 1) % SZ(regions[i])] == regions[k][l]) || (regions[i][j] == regions[k][l] && regions[i][(j + 1) % SZ(regions[i])] == regions[k][(l + 1) % SZ(regions[k])])) {
            // cout << "Edge " << i << ' ' << k << '\n';
            adj[i][k] = adj[k][i] = 1;
            break;
          }
        }
      }
    }
  }
    
          
  // FOR(i, 0, m) 
      // FOR(j, 0, m) 
        // cout << adj[i][j] << " \n"[j == m - 1]; 

  vector<vector<int>> dist = adj;
  FOR(k, 0, m) 
    FOR(i, 0, m) 
      FOR(j, 0, m) 
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  

  int minCross = INF;
  int minRegion = -1;
  FOR(endRegion, 0, m){
    int cross = 0;
    for(auto & member : members){
      int minCrossMember = INF;

      for(auto & startRegion : cities[member]){
        minCrossMember = min(minCrossMember, dist[startRegion][endRegion]);
      }

      cross += minCrossMember;
    }

    if(cross >= minCross)
      continue;

    minCross = cross;
    minRegion = endRegion + 1;
  }
  cout << minCross << ENDL << minRegion;

  return 0;
}