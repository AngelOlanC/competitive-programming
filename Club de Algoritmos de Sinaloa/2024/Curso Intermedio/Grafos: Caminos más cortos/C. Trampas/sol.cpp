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

constexpr int N = 305 * 305;
constexpr int INF = 1 << 28;
constexpr int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};

int n, m;
char c[N];
vector<pi> g[N];
int d[N];

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int encode(int i, int j) {
  return i * m + j;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int si, sj, ei, ej;
  cin >> n >> m >> si >> sj;

  si--, sj--;

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      int k = encode(i, j);
      cin >> c[k];

      if (c[k] == 'S') {
        ei = i, ej = j;
        continue;
      }
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      int k = encode(i, j);
      if (c[k] == '#') {
        continue;
      }
      FOR (dir, 0, 4) {
        int ii = i + di[dir], jj = j + dj[dir], kk = encode(ii, jj);
        if (valid(ii, jj) && c[kk] != '#') {
          g[k].pb({kk, c[kk] == 'x'});
        }
      }
    }
  }

  fill(d, d + N, INF);
  int ks = encode(si, sj);
  d[ks] = c[ks] == 'x';
  
  deque<int> dq;
  dq.push_back(ks);

  int ke = encode(ei, ej);
  
  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();

    for (auto &[v, w] : g[u]) {
      if (d[u] + w < d[v]) {
        d[v] = d[u] + w;
        if (v == ke) {
          cout << d[v] << ENDL;
          return 0;
        }
        if (!w) {
          dq.push_front(v);
        } else {
          dq.push_back(v);
        }
      }
    }
  }
  cout << 0 << ENDL;

  return 0;
}