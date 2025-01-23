#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

inline int sub(int x, int y, int m) {
  int ret = x - y;
  if (ret < 0) {
    ret += m;
  }
  return ret;
}

int find_min_z(int x, int y, int dx, int dy, int mx, int my, vector<vector<bool>>& vis) {
  if (!x && !y) {
    return 0;
  }
  if (vis[x][y]) {
    return -1000000000;
  }
  vis[x][y] = true;
  return 1 + find_min_z(sub(x, dx, mx), sub(y, dy, my), dx, dy, mx, my, vis);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  const i64 OFFSET = 10000000000000ll;

  int it = 0;

  i64 ans = 0;
  string line1, line2, line3;
  while (getline(cin, line1) && getline(cin, line2) && getline(cin, line3)) {
    ++it;
    stringstream ss(line1);
    string aux_s;
    char aux_c;
    int dx_a, dy_a;
    ss >> aux_s >> aux_s >> aux_c >> aux_c >> dx_a >> aux_c >> aux_c >> aux_c >> dy_a;
    ss = stringstream(line2);
    int dx_b, dy_b;
    ss >> aux_s >> aux_s >> aux_c >> aux_c >> dx_b >> aux_c >> aux_c >> aux_c >> dy_b;
    i64 x, y;
    ss = stringstream(line3);
    ss >> aux_s >> aux_c >> aux_c >> x >> aux_c >> aux_c >> aux_c >> y;

    x += OFFSET;
    y += OFFSET;

    // cout << dx_a << ' ' << dy_a << ' ' << dx_b << ' ' << dy_b << ' ' << x << ' ' << y << '\n';

    vector<vector<bool>> vis(150, vector<bool>(150));
    int min_z = find_min_z(x % dx_b, y % dy_b, dx_a % dx_b, dy_a % dy_b, dx_b, dy_b, vis);
    if (min_z < 0) {
      getline(cin, line1);
      continue;
    }
    
    i64 k0 = (x - dx_a * min_z) / dx_b, k1 = (y - dy_a * min_z) / dy_b;
    if (k0 == k1) {
      ans += min_z * 3 + k0;
    }

    getline(cin, line1);
  }
  cout << ans << '\n';

  return 0;
}