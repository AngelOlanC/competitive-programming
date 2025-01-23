#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MAX = 3002, OFFSET = MAX / 2;

int a[MAX][MAX];
int b[MAX][MAX];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    char t;
    int x, y, r;
    cin >> t >> x >> y >> r;
    
    x += OFFSET;
    y += OFFSET;

    r >>= 1;

    if (t == 'A') {
      ++a[x - r][y - r];
      --a[x - r][y + r];
      --a[x + r][y - r];
      ++a[x + r][y + r];
      continue;
    }
    
  }


  return 0;
}