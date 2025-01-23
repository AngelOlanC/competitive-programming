#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

vector<int> decompose(i64 x) {
  vector<int> ret;
  while (x) {
    ret.push_back(int(x % 10));
    x /= 10;
  }
  return ret;
}

bool canWithNoCarry(int d, int c, int x) {
  if (c == 1) {
    return d == x || (!x && d < 5);
  }
  if (c == 2) {
    return !x && d >= 5;
  }
  return d == x || !x;
}

bool canWithCarry(int d, int c, int x) {
  if (c == 1) {
    return d + 1 == x || (!x && d < 5) || (x == 1 && d < 5);
  }
  if (c == 2) {
    return (!x && d >= 4) || (x == 1 && d >= 5);
  }
  return d + 1 == x || x <= 1;
}

i64 prevDp[3][2], currDp[3][2];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    i64 x, z;
    cin >> x >> z;

    vector<int> dx = decompose(x), dz = decompose(z);

    while ((int)dx.size() < (int)dz.size()) {
      dx.push_back(0);
    }
    while ((int)dz.size() < (int)dx.size()) {
      dz.push_back(0);
    }

    prevDp[1][0] = prevDp[1][1] = 0;
    prevDp[0][0] = prevDp[0][1] = prevDp[2][0] = prevDp[2][1] = 1;

    for (int i = 0; i < (int)dx.size(); ++i) {
      for (int c = 1; c <= 3; ++c) {
        for (int less = 0; less <= 1; ++less) {
          int maxD = less ? 9 : dz[i];
          for (int d = 0; d <= maxD; ++d) {
            bool newLess = less || d < dz[i];
            int newC = int(canWithNoCarry(d, c, dx[i])) | (int(canWithCarry(d, c, dx[i])) << 1); 
            if (newC) {
              currDp[c - 1][less] += prevDp[newC - 1][newLess];
            }
          }
        }
      }
      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 2; ++b) {
          swap(prevDp[a][b], currDp[a][b]);
          currDp[a][b] = 0;
        }
      }
    }
    cout << prevDp[2][0] << '\n';
  }

  return 0;
}