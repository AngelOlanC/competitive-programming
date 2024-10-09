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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;
  
  set<pi> moves;
  FOR (i, 0, n) {
    int dx, dy;
    cin >> dx >> dy;
    moves.insert({dx, dy});
  }
  
  auto check = [&](int x, int y) -> bool {
    if (x == bx && y == by) return true;
    if (moves.count(make_pair(bx - x, by - y))) return true;
    for (auto &[dx, dy] : moves) {
      int xx = x + dx, yy = y + dy;
      if (xx <= 0 || xx > n || yy <= 0 || yy > n) continue;
      if (moves.count(make_pair(bx - xx, by - yy))) return true;
    }
    return false;
  };

  if (check(ax, ay)) {
    cout << "Alice wins" << ENDL;
    return 0;
  }

  {
    set<pi> new_moves;
    for (auto &[dx, dy] : moves) new_moves.insert({-dx, -dy});
    swap(moves, new_moves);
  }

  int k = 50;
  FOR (i, 0, k) {
    int x = rnd(1, n), y = rnd(1, n);
    if (!check(x, y)) {
      cout << "tie " << x << ' ' << y << ENDL;
      return 0;
    }
  }
  cout << "Bob wins" << ENDL;
  return 0;
}