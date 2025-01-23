#include <bits/stdc++.h>
using namespace std;

inline int add(int x, int y, int m) {
  int ret = x + y;
  if (ret >= m) {
    ret -= m;
  }
  return ret;
}

inline int sub(int x, int y, int m) {
  int ret = x - y;
  if (ret < 0) {
    ret += m;
  }
  return ret;
}

bool calc_cycles(int &k, vector<int>& p, vector<int>& cycle_id, vector<int>& pos_in_cycle) {
  int n = p.size();
  for (int i = 0, c_id = 0; i < n; ++i) {
    if (cycle_id[i] != -1) {
      continue;
    }
    int j = i, len = 0, pos = 0;
    do {
      ++len;
      cycle_id[j] = c_id;
      pos_in_cycle[j] = pos++;
      j = p[j];
    } while (j != i);
    if (k != -1 && len != k) {
      return false;
    }
    k = len;
    ++c_id;
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> mat(n, vector<int>(n));
  for (int i = 0, id = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      mat[i][j] = id++;
    }
  }
  vector<int> pr(n), pc(n);
  iota(pr.begin(), pr.end(), 0);
  iota(pc.begin(), pc.end(), 0);
  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    --a;
    --b;
    if (op == 'R') {
      swap(pr[a], pr[b]);
    } else {
      swap(pc[a], pc[b]);
    }
  }
  int k = -1;
  vector<int> cycle_id_r(n, -1), pos_in_cycle_r(n, -1);
  vector<int> cycle_id_c(n, -1), pos_in_cycle_c(n, -1);
  if (!calc_cycles(k, pr, cycle_id_r, pos_in_cycle_r) || !calc_cycles(k, pc, cycle_id_c, pos_in_cycle_c)) {
    cout << "*\n";
    return 0;
  }
  int b = n / k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = add(cycle_id_r[i], cycle_id_c[j], b) * k + sub(pos_in_cycle_r[i], pos_in_cycle_c[j], k) + 1;
      cout << x << " \n"[j == n - 1];
    }
  }
}