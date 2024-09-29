#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
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

int N, M, D, GR, GC;

vector<vi> dijkstra_dist(vector<vi> a) {
  vector<vi> d(N, vi(M, 1e9));
  priority_queue<array<int, 3>> pq;
  pq.push({0, GR, GC});
  d[GR][GC] = 0;
  while (!pq.empty()) {
    auto [dst, i, j] = pq.top();
    pq.pop();
    dst = -dst;
    if (dst > d[i][j]) continue;
    FOR (dir, 0, 4) {
      int ii = i + di[dir], jj = j + dj[dir];
      if (ii == -1 || ii == N || jj == -1 || jj == M || dst + abs(a[i][j] - a[ii][jj]) >= d[ii][jj]) continue;
      d[ii][jj] = dst + abs(a[i][j] - a[ii][jj]);
      pq.push({-dst, ii, jj});
    }
  }
  return d;
}

vector<vi> dijkstra_diff(vector<vi> a) {
  vector<vi> d(N, vi(M, 1e9));
  priority_queue<array<int, 3>> pq;
  pq.push({0, GR, GC});
  d[GR][GC] = 0;
  while (!pq.empty()) {
    auto [dst, i, j] = pq.top();
    pq.pop();
    dst = -dst;
    if (dst > d[i][j]) continue;
    FOR (dir, 0, 4) {
      int ii = i + di[dir], jj = j + dj[dir];
      if (ii == -1 || ii == N || jj == -1 || jj == M || max(dst, abs(a[i][j] - a[ii][jj])) >= d[ii][jj]) continue;
      d[ii][jj] = max(dst, abs(a[i][j] - a[ii][jj]));
      pq.push({-dst, ii, jj});
    }
  }
  return d;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> N  >> M >> D >> GR >> GC;

  vector<vi> a(N, vi(M));
  FOR (i, 0, N) FOR (j, 0, M)  cin >> a[i][j];

  vector<vi> d1 = dijkstra_dist(a), d2 = dijkstra_diff(a);

  int mx_d = 0, mx_diff = 0;
  FOR (i, 0, N) FOR (j, 0, M) mx_d = max(mx_d, d1[i][j]), mx_diff = max(mx_diff, d2[i][j]);
  if (mx_d > D) {
    cout << 
  }

  return 0;
}