#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int ans = 0;
  string line1, line2, line3;
  while (getline(cin, line1) && getline(cin, line2) && getline(cin, line3)) {
    stringstream ss(line1);
    string aux_s;
    char aux_c;
    int a_dx, a_dy;
    ss >> aux_s >> aux_s >> aux_c >> aux_c >> a_dx >> aux_c >> aux_c >> aux_c >> a_dy;
    ss = stringstream(line2);
    int b_dx, b_dy;
    ss >> aux_s >> aux_s >> aux_c >> aux_c >> b_dx >> aux_c >> aux_c >> aux_c >> b_dy;
    int px, py;
    ss = stringstream(line3);
    ss >> aux_s >> aux_c >> aux_c >> px >> aux_c >> aux_c >> aux_c >> py;

    int mn = 1e9;
    for (int i = 0; i <= 100; ++i) {
      int x = a_dx * i, y = a_dy * i;
      if (x > px || y > py) {
        break;
      }
      int k = (px - x) / b_dx;
      x = x + b_dx * k;
      y = y + b_dy * k;
      if (x == px && y == py) {
        mn = min(mn, 3 * i + k);
      }
    }
    if (mn != 1e9) {
      ans += mn;
    }

    getline(cin, line1);
  }
  cout << ans << '\n';

  return 0;
}