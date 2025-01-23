#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int rnd(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

inline void shuffle(vector<int>& v) {
  shuffle(v.begin(), v.end(), rng);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int r = rnd(3, 100), c = rnd(3, 100);
  cout << r << ' ' << c << '\n';

  vector<int> v(r * c);
  iota(v.begin(), v.end(), 0);
  shuffle(v);

  auto encode = [&](int i, int j) -> int {
    return i * c + j;
  };

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << v[encode(i, j)] << " \n"[j == c - 1];
    }
  }

  int m = rnd(1, 100);
  cout << m << '\n';

  while (m--) {
    int op = rnd(0, 1);
    if (!op) {
      cout << "move " << rnd(1, r * c * r) << '\n';
    } else {
      int a = rnd(1, r), b = rnd(1, c), k;
      do  {
        k = rnd(1, r * c * 10);
      } while (k == v[encode((a - 2 + r) % r, b - 1)] || k == v[encode(a % r, b - 1)]);
      cout << "change " << a << ' ' << b << ' ' << k << '\n';
    }
  }

  return 0;
}