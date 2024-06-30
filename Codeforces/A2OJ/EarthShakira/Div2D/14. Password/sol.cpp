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

#define N 1000010

int pi[N];
string s;

void build_pi() {
  FOR (i, 1, SZ(s)) {
    int j = pi[i - 1];
    while (j && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s;

  build_pi();

  int j = pi[SZ(s) - 1];

  if (!j) {
    cout << "Just a legend" << ENDL;
    return 0;
  }

  FOR (i, 1, SZ(s) - 1) {
    if (pi[i] == j) {
      cout << s.substr(0, j) << ENDL;
      return 0;
    }
  }

  j = pi[j - 1];
  if (j) {
    cout << s.substr(0, j) << ENDL;
    return 0;
  }

  cout << "Just a legend" << ENDL;
  return 0;
}