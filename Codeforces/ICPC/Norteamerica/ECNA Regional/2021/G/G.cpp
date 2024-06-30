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

string stringify(vector<pi> v) {
  string s = "";
  for (auto &[x, cnt] : v) {
    s += to_string(cnt) + to_string(x);
  }
  return s;
}

vector<pi> nice(vi cnt) {
  vector<pi> v;
  FOR (i, 0, 10) {
    if(cnt[i]) {
      v.pb({i, cnt[i]});
    }
  }
  return v;
}

vector<pi> vectorify(string s) {
  vi cnt(10, 0);
  FOR (i, 0, SZ(s)) {
    cnt[s[i] - '0']++;
  }
  return nice(cnt);
}

vector<pi> next(vector<pi> v) {
  vi cnt(10, 0);
  for (auto &[x, c] : v) {
    cnt[x]++;
    cnt[c]++;
  }
  return nice(cnt);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  if (s == t) {
    cout << 1 << ENDL;
    return 0;
  }

  unordered_set<string> um;
  um.insert(s);

  vector<pi> actual = vectorify(s);

  if (stringify(actual) == t) {
    cout << 2 << ENDL;
    return 0;
  }
  um.insert(stringify(actual));

  FOR (i, 2 + (stringify(actual) != s), 101) {
    actual = next(actual);
    string str = stringify(actual);
    if (str == t) {
      cout << i << ENDL;
      return 0;
    }
    if (um.count(str)) {
      cout << "Does not appear" << ENDL;
      return 0;
    }
    um.insert(str);
  }
  cout << "I'm bored" << ENDL;
  return 0;
}