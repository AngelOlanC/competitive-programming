#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<tuple<int, int, int, int>> type1;
  for (int i = 30; i; --i) {
    // +2 x2 or only x2
    int sz = (int)type1.size();
    if (sz == 1) {
      ++sz;
      type1.emplace_back(sz, sz + 1, sz, sz);
    } else if (sz >= 2) {
      type1.back() = make_tuple(sz, sz + 1, sz, 1);
      ++sz;
      type1.emplace_back(sz, sz + 1, sz, sz);
    }
    if ((n >> i) & 1) {
      ++sz;
      type1.emplace_back(sz, sz + 1, sz, sz);
    }
  }

  cout << (int)type1.size() + 1 << '\n';
  for (auto [a, x, b, y] : type1) {
    cout << "POP " << a << " GOTO " << x << "; PUSH " << b << " GOTO " << y << '\n';
  }
  cout << "HALT; PUSH 128 GOTO 1\n";

  return 0;
}