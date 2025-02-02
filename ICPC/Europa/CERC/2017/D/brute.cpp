#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

void updLink(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& d) {
  const int r = (int)nums.size(), c = (int)nums[0].size();

  int best = -1;
  for (int x = 0; x <= 1; ++x) {
    if (nums[(i + x + r) % r][(j + 1) % c] > nums[(i + best + r) % r][(j + 1) % c]) {
      best = x;
    }
  }
  d[i][j] = best;
}

void go(int &i, int& j, int k, vector<vector<int>>& d) {
  const int r = (int)d.size(), c = (int)d[0].size();
  while (k--) {
    i = (i + d[i][j] + r) % r;
    j = (j + 1) % c;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int r, c;
  cin >> r >> c;

  vector<vector<int>> nums(r, vector<int>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> nums[i][j];
    }
  }

  vector<vector<int>> d(r, vector<int>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      updLink(i, j, nums, d);
    }
  }

  int m;
  cin >> m;

  int i = 0, j = 0;
  while (m--) {
    string op;
    cin >> op;

    if (op[0] == 'c') {
      int a, b, e;
      cin >> a >> b >> e;
      --a, --b;

      nums[a][b] = e;
      for (int x = -1; x <= 1; ++x) {
        updLink((a - x + r) % r, (b - 1 + c) % c, nums, d);
      }
      continue;
    }
    int k;
    cin >> k;
    
    go(i, j, k, d);

    cout << i + 1 << ' ' << j + 1 << '\n';
  }

  return 0;
}