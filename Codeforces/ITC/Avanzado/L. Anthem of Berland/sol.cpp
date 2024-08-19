#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

#define N 100010

string s, t;
int pi[N];

void build_pi() {
  FOR (i, 1, SZ(t)) {
    int j = pi[i - 1];
    while (j && t[j] != t[i]) {
      j = pi[j - 1];
    }
    if (t[j] == t[i]) {
      j++;
    }
    pi[i] = j;
  }
}

int aut[N][26]; 

void compute_automaton() {
    for (int i = 0; i < SZ(t); i++) {
      for (int c = 0; c < 26; c++) {
        if (i > 0 && 'a' + c != t[i])
            aut[i][c] = aut[pi[i-1]][c];
        else
            aut[i][c] = i + ('a' + c == t[i]);
      }
    }
}

vector<vi> dp;

int solve(int i, int j) {
  if (i == SZ(s)) {
    return 0;
  }

  int &ans = dp[i][j];
  if (~ans) {
    return ans;
  }

  if (s[i] != '?') {
    j = aut[j][s[i] - 'a'];
    bool complete = j == (SZ(t) - 1);
    return ans = complete + solve(i + 1, j);
  }

  ans = 0;
  FOR (c, 0, 26) {
    int jj = aut[j][c];
    bool complete = jj == (SZ(t) - 1); 
    ans = max(ans, complete + solve(i + 1, jj));
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s >> t;

  t += '#';

  build_pi();
  compute_automaton();

  dp.assign(SZ(s) + 5, vi(SZ(t) + 5, -1));
  cout << solve(0, 0) << ENDL;

  return 0;
}