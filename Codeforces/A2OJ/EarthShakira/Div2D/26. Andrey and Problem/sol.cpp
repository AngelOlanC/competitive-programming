#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define tcT template <class T \
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define ENDL '\n'

using edge = tuple<int, ll, ll>;

const int INF = 1e9;                             // large enough
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

constexpr int MAXN = 2005;

int dist[MAXN], pairU[MAXN], pairV[MAXN], c1, c2;
vi graph[MAXN];

bool bfs(){
    queue<int> q;

    for(int u = 1; u <= c1; u++){
        if(!pairU[u]){
            dist[u] = 0;
            q.push(u);
        }
        else
            dist[u] = INF;
    }

    dist[0] = INF;

    while(!q.empty()){
        int u = q.front(); q.pop();

        if(dist[u] < dist[0]){
            for(int v : graph[u]){
                if(dist[pairV[v]] == INF){
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]); 
                }
            }
        }
    }

    return dist[0] != INF;
}

bool dfs(int u){
    if(u){
        for(int v : graph[u]){
            if (dist[pairV[v]] == dist[u] + 1){
                if (dfs(pairV[v])){
                    pairU[u] = v;
                    pairV[v] = u;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp(){
    int result = 0;

    while(bfs())
        for(int u = 1; u <= c1; u++)
            if(!pairU[u] && dfs(u))
                result++;

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, p, d; cin >> n >> p >> d;
    int valid[n][n]; memset(valid, 0, sizeof valid);
    for (int k = 0; k < p; k++) {
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            for (int j = i - 1; j >= 0 && j >= i - d; j--)
                valid[x][j]++;
            for (int j = i; j <= i + d && j < n; j++)
                valid[x][j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (valid[i][j] == p)
                graph[i + 1].push_back(j + n + 1);
    }
    c1 = c2 = n;
    if (hopcroftKarp() != n) {
        cout << -1 << ENDL;
        return 0;
    }

    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[pairU[i + 1] - n - 1] = i;
    }

    for (int i = 0; i < n; i++) 
        cout << ans[i] << ' ';
    cout << ENDL;

    return 0;
}