#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  map<string, int> ids;
  vector<string> names;
  vector<bitset<525>> bts;

  auto get_id = [&](string name) -> int {
    if (ids.find(name) != ids.end()) {
      return ids[name];
    }
    int id = (int)ids.size();
    names.push_back(name);
    bts.push_back(bitset<525>());
    return ids[name] = id;
  };

  string s;
  while (cin >> s) { 
    string a = "", b = "";
    a += s[0];
    a += s[1];
    b += s[3];
    b += s[4];
    int id_a = get_id(a), id_b = get_id(b);
    bts[id_a].set(id_b);
    bts[id_b].set(id_a);
  }

  auto f = [&](auto&& self, bitset<525> curr) -> int {
    int ret = 0;
    for (int i = curr._Find_first(); i < (int)curr.size(); i = curr._Find_next(i)) {
      bitset<525> curr2 = curr;
      curr2 &= bts[i];
      ret = max(ret, 1 + self(self, curr2));
    }
    return ret;
  };

  bitset<525> curr;
  for (int i = 0; i < 525; ++i) {
    curr.set(i);
  }
  
  cout << f(f, curr) << '\n';

  return 0;
}