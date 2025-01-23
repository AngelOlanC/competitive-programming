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

void go(int& i, int& j, int k, vector<vector<int>>& d) {
  const int r = (int)d.size(), c = (int)d[0].size();

  while (k--) {
    i = (i + d[i][j] + r) % r;
    j = (j + 1) % c;
  }
}

void move(int& i, int& j, int k, vector<int>& jmp, vector<vector<int>>& d) {
  const int r = (int)d.size(), c = (int)d[0].size();

  if (k < c - j) {
    go(i, j, k, d);
    return;
  }
  
  k -= c - j;
  go(i, j, c - j, d);

  vector<int> id(r, -1);
  for (int t = 0; k >= c; ++t, k -= c) {
    if (id[i] != -1) {
      k %= (t - id[i]) * c;
      break;
    }
    id[i] = t;
    i = jmp[i];
  }
  while (k >= c) {
    i = jmp[i];
    k -= c;
  }
  go(i, j, k, d);
}

void updJmp(int a, int b, int nxt, vector<vector<int>>& nums, vector<vector<int>>& d, vector<int>& jmp) {
  const int r = (int)nums.size(), c = (int)nums[0].size();

  int s = a, l = 1;
  for (int col = (b - 1 + c) % c; col >= 0; --col) {
    if (d[s][col] == -1) {
      s = (s + 1) % r;
      --l;
    } else if (int ss = (s - 1 + r) % r; d[ss][col] == 1){
      s = ss;
      ++l;
    }
    int e = (s + l - 1 + r) % r;
    if (d[e][col] == 1) {
      --l;
    } else if (int ee = (e + 1) % r; d[ee][col] == -1 && l != r) {
      ++l;
    }
    if (l == r) {
      break;
    }
    if (l <= 0) {
      return;
    }
  }

  while (l--) {
    jmp[s] = nxt;
    s = (s + 1) % r;
  }
};

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

  vector<int> jmp(r);
  for (int i = 0; i < r; ++i) {
    int ii = i, jj = 0;
    go(ii, jj, c, d);
    jmp[i] = ii;
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
        updLink((a + x + r) % r, (b - 1 + c) % c, nums, d);
      }

      if (!b) {
        for (int x = -2; x <= 2; ++x) {
          const int aa = (a + x + r) % r;
          updJmp(aa, b, aa, nums, d, jmp);
        }
      } else {
        for (int x = -2; x <= 2; ++x) {
          int aa = (a + x + r) % r, bb = b;
          go(aa, bb, c - b, d);
          updJmp((a + x + r) % r, b, aa, nums, d, jmp);
        }
      }
      continue;
    }
    int k;
    cin >> k;

    move(i, j, k, jmp, d);

    cout << i + 1 << ' ' << j + 1 << '\n';
  }
  return 0;
}