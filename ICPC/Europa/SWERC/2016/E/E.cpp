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

struct AhoCorasick {
  enum { alpha = 27,
         first = 'a' };  // change this!
  struct Node {
    // (nmatches is optional)
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vi backp;
  void insert(string& s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int& m = N[n].next[c - first];
      if (m == -1) {
        n = m = SZ(N);
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  // O(sum|pat| * C)
  void init(vector<string>& pat) {
    N.pb(-1);
    FOR(i, 0, SZ(pat))
    insert(pat[i], i);
    N[0].back = SZ(N);
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      FOR(i, 0, alpha) {
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

constexpr int MOD = 1000003, maxn = 20 + 5, maxnodes = 50 * 20 + 5;

char fin = 'z' + 1;
char eq[10] = {'o', 'i', fin, 'e', fin, 's', fin, 't', fin, fin};

int a, b, n;
int memo[maxn][maxnodes][2][2][2];
AhoCorasick aho;

int dp(int i, int u, int lo, int up, int di) {
  if (i > b || aho.N[u].nmatches) return 0;
  
  int &ans = memo[i][u][lo][up][di];
  if (~ans) return ans;

  ans = i >= a && lo && up && di;

  FOR (c, 0, 26) {
    ans += dp(i + 1, aho.N[u].next[c], 1, up, di);
    ans %= MOD;
    ans += dp(i + 1, aho.N[u].next[c], lo, 1, di);
    ans %= MOD;
  }

  FOR (c, 0, 10) {
    ans += dp(i + 1, aho.N[u].next[eq[c] - 'a'], lo, up, 1);
    ans %= MOD;
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> a >> b >> n;

  vector<string> p(n);
  for (auto &pi : p) {
    cin >> pi;
  }

  aho.init(p);

  memset(memo, -1, sizeof memo);

  cout << dp(0, 0, 0, 0, 0) << ENDL;

  return 0;
}