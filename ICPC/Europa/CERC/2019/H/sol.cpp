#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct AhoCorasick {
  enum { alpha = 26,
         first = 'a' };
  struct Node {
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vector<int> backp;
  void insert(string& s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int& m = N[n].next[c - first];
      if (m == -1) {
        n = m = (int)N.size();
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  AhoCorasick(vector<string>& pat) : N(1, -1) {
    for (int i = 0; i < (int)pat.size(); ++i) {
      insert(pat[i], i);
    }
    N[0].back = (int)N.size();
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; ++i) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }
};

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline int sub(int x, int y) {
  return x >= y ? x - y : x - y + MOD;
}

inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

constexpr int N = 100 + 5;

int g[N][N], ret[N][N], aux[N][N];

void mul(int a[N][N], int b[N][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      aux[i][j] = 0;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        aux[i][j] = add(aux[i][j], mul(a[i][k], b[k][j]));
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      a[i][j] = aux[i][j];
    }
  }
}

void be(int a[N][N], int n) {
  for (int i = 0; i < N; ++i) {
    ret[i][i] = 1;
  }
  while (n) {
    if (n & 1) {
      mul(ret, a);
    }
    mul(a, a);
    n >>= 1;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      a[i][j] = ret[i][j];
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<string> pat(m);
  for (auto& p : pat) {
    int len;
    cin >> len >> p;
  }

  AhoCorasick aho(pat);
  const int N = (int)aho.N.size();

  for (int u = 0; u < N; ++u) {
    for (int c = 0; c < 26; ++c) {
      int v = aho.N[u].next[c];
      if (!aho.N[v].nmatches) {
        ++g[u][v];
      }
    }
  }

  be(g, n);

  int ans = 0;
  for (int u = 0; u < N; ++u) {
    ans = add(ans, g[0][u]);
  }
  cout << ans << '\n';

  return 0;
}