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

const int maxn = 1000000 + 5;

vector<string> read_tree() {
  string line;
  getline(cin, line);
  
  stringstream ss(line);
  string s = "", aux;
  while (ss >> aux) {
    s += aux;
  }
  string acum = "";
  vector<string> ans;
  for (auto &c : s) {
    if (c != '(' && c != ')') {
      acum += c;
      continue;
    }
    if (SZ(acum)) {
      ans.pb(acum);
    }
    acum = c;
    ans.pb(acum);
    acum = "";
  }
  if (SZ(acum)) {
    ans.pb(acum);
  }
  return ans;
}

void evaluate(int &i, vector<string> &vs, vi &p, int par = -1) {
  int u = stoi(vs[i]), open = 0;
  p[u] = par;
  while (++i < SZ(vs)) {
    if (vs[i] == "(") {
      open++;
      evaluate(++i, vs, p, u);
    }
    if (i == SZ(vs)) {
      return;
    }
    if (vs[i] == ")") {
      open--;
      if (open == -1) {
        return;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  vector<string> vs = read_tree(), vt = read_tree();

  if (min(SZ(vs), SZ(vt)) == 1) {
    cout << (vs == vt ? "Yes" : "No") << ENDL;
    return 0;
  }

  vi ps(maxn, -1), pt(maxn, -1);

  int is = 0, it = 0;
  evaluate(is, vs, ps);
  evaluate(it, vt, pt);

  FOR (i, 0, maxn) {
//    cout << i << ' ' << ps[i] << ' ' << pt[i] << ENDL;
    if (ps[i] != pt[i]) {
      cout << "No" << ENDL;
      return 0;
    }
  }
  cout << "Yes" << ENDL;
  return 0;
}