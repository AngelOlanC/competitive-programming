#include <bits/stdc++.h>
#include <bits/extc++.h>

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

const ll INF = numeric_limits<ll>::max() / 4;
struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vi seen;
  vector<vi> ind;
	vector<ll> dist, pi;
	vector<edge*> par;

	MCMF(int N) : N(N), ind(N, vi(N)), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		if (from == to) return;
    ind[from][to] = SZ(ed[from]);
  	ed[from].push_back(edge{ from,to,SZ(ed[to]),cap,cost,0 });
		ed[to].push_back(edge{ to,from,SZ(ed[from])-1,0,-cost,0 });
	}

	void path(int s) {
		fill(ALL(seen), 0);
		fill(ALL(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({ 0, s });

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (edge& e : ed[s]) if (!seen[e.to]) {
				ll val = di - pi[e.to] + e.cost;
				if (e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
					if (its[e.to] == q.end())
						its[e.to] = q.push({ -dist[e.to], e.to });
					else
						q.modify(its[e.to], { -dist[e.to], e.to });
				}
			}
		}
		FOR (i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
	}

  ll flow(int a, int b) {
    edge e = ed[a][ind[a][b]];
    return e.flow;
  }

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);

			totflow += fl;
			for (edge* x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		FOR (i, 0, N) for(edge& e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost/2};
	}
};

const int maxn = 50 + 5;

int a[maxn][maxn][2], b[maxn][maxn][2];
string ans_gate[maxn];
int ans_station[maxn];
int assigned_worker[maxn];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  FOR (i, 0, n) {
    FOR (j, 0, n) {
      FOR (k, 0, 2) {
        cin >> a[i][j][k];
      }
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, n) {
      FOR (k, 0, 2) {
        cin >> b[i][j][k];
      }
    }
  }

  int N = 1 + n + 2 * n + 2 * n + n + 1; 

  ll ans = 1e9;
  FOR (k, 0, n + 1) {
    MCMF mcmf(N);
    
    FOR (i, 0, n) {
      mcmf.addEdge(0, 1 + i, 1, 0); // SOURCE - W

      int u = 1 + n + 2 * n + 2 * n + i;
      int v = 1 + n + 2 * n + 2 * n + n;
      mcmf.addEdge(u, v, 1, 0); // STATIONS - SINK

      // GATES - INT
      bool b_taken = i >= k;
      u = 1 + n + 2 * i + b_taken;
      v = 1 + n + 2 * n + 2 * i + b_taken;
      mcmf.addEdge(u, v, 1, 0);
    }

    FOR (i, 0, n) { // W - GATES
      int u = 1 + i;
      FOR (j, 0, n) {
        bool b_taken = (j >= k);
        int v = 1 + n + 2 * j + b_taken;
        mcmf.addEdge(u, v, 1, a[i][j][b_taken]); 
      }
    }
    
    FOR (j, 0, n) { // INT - STATIONS
      bool b_taken = (j >= k);
      int u = 1 + n + 2 * n + 2 * j + b_taken;
      FOR (i, 0, n) {
        int v = 1 + n + 2 * n + 2 * n + i;
        mcmf.addEdge(u, v, 1, b[i][j][b_taken]);
      }
    }

    auto [flow, cost] = mcmf.maxflow(0, 1 + n + 2 * n + 2 * n + n);

    assert(flow == n);

    if (cost >= ans) {
      continue;
    }

    ans = cost;

    memset(assigned_worker, -1, sizeof assigned_worker);
    memset(ans_station, -1, sizeof ans_station);

    FOR (i, 0, n) {
      int u = 1 + i;
      FOR (j, 0, n) {
        bool b_taken = (j >= k);
        int v = 1 + n + 2 * j + b_taken;
        if (mcmf.flow(u, v)) {
          char c = b_taken ? 'B' : 'A';
          ans_gate[i] = to_string(j + 1) + c;
          assigned_worker[j] = i;
        }
      }
    }

    FOR (i, 0, n) {
      bool b_taken = (i >= k);
      int u = 1 + n + 2 * n + 2 * i + b_taken;
      FOR (j, 0, n) {
        int v = 1 + n + 2 * n + 2 * n + j;
        if (mcmf.flow(u, v)) {
          ans_station[assigned_worker[i]] = j + 1; 
        }
      }
    }
  }
  cout << ans << ENDL;
  FOR (i, 0, n) {
    cout << i + 1 << ' ' << ans_gate[i] << ' ' << ans_station[i] << ENDL;
  }
}