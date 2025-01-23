#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<i64> v;
  string line;
  while (getline(cin, line) && !line.empty()) {
    stringstream ss(line);
    string aux;
    int x;
    ss >> aux >> aux >> x;
    v.push_back(x);
  }

  getline(cin, line);
  stringstream ss(line);
  string aux_s;
  ss >> aux_s;
  char aux_c;
  cin >> aux_s;
  vector<int> inst;
  while (ss.good()) {
    int x, y;
    ss >> x >> aux_c >> y;
    if (ss.good()) {
      ss >> aux_c;
    }
    inst.push_back(x);
    inst.push_back(y);
  }

  for (int i = 0; i < (int)inst.size(); i += 2) {
    int op = inst[i];
    int lit = inst[i + 1];
    i64 combo = lit;
    if (lit >= 4 && lit < 7) {
      combo = v[lit - 4];
    }
    if (op == 0) {
      v[0] >>= min(60ll, combo);
      continue;
    }
    if (op == 1) {
      v[1] ^= lit;
      continue;
    }
    if (op == 2) {
      v[1] = combo % 8;
      continue;
    }
    if (op == 3) {
      if (!v[0]) {
        continue;
      }
      if (i != lit) {
        i = lit - 2;
      }
      continue;
    }
    if (op == 4) {
      v[1] ^= v[2];
      continue;
    }
    if (op == 5) {
      cout << combo % 8 << ',';
      continue;
    }
    if (op == 6) {
      v[1] = v[0] >> min(60ll, combo);
      continue;
    }
    if (op == 7) {
      v[2] = v[0] >> min(60ll, combo);
      continue;
    }
  }

  return 0;
}