#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  map<string, int> mp;

  string line;
  while (getline(cin, line) && !line.empty()) {
    string s = "";
    s += line[0];
    s += line[1];
    s += line[2];
    mp[s] = line[5] - '0';
  }

  map<string, tuple<string, string, string>> eq;

  while (getline(cin, line)) {
    stringstream ss(line);
    string a, op, b, c;
    ss >> a >> op >> b >> c >> c;
    eq[c] = {a, op, b};
  }

  auto f = [&](auto&& f, string c) -> void {
    auto [a, op, b] = eq[c];
    if (mp.find(a) == mp.end()) {
      f(f, a);
    }
    if (mp.find(b) == mp.end()) {
      f(f, b);
    }
    if (op == "OR") {
      mp[c] = mp[a] | mp[b];
    } else if (op == "AND") {
      mp[c] = mp[a] & mp[b];
    } else if (op == "XOR") {
      mp[c] = mp[a] ^ mp[b];
    }
  };

  for (auto &[c, v] : eq) {
    if (mp.find(c) == mp.end()) {
      f(f, c);
    }
  }

  auto to_id = [](int i) -> string {
    if (i < 10) {
      return "z0" + to_string(i);
    }
    return "z" + to_string(i);
  };

  i64 ans = 0;
  for (int i = 0; mp.find(to_id(i)) != mp.end(); ++i) {
    if (mp[to_id(i)]) {
      ans |= 1ll << i;
    }
  }
  cout << ans << '\n';
  cout << (int)mp.size() << '\n';

  return 0;
}