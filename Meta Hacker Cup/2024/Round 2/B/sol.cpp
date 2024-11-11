#include <bits/stdc++.h>
using namespace std;

int pot7[7];

int encode(vector<int> rows) {
  int state = 0;
  for (int i = 0; i < 7; ++i) {
    state += pot7[i] * rows[i];
  }
  return state;
}

vector<int> decode(int state) {
  vector<int> rows(7);
  for (int i = 6; i >= 0; --i) {
    rows[i] = state / pot7[i];
    state %= pot7[i];
  }
  return rows;
}

int a[7][6];
bool vis_start[7*7*7*7*7*7*7];

void dfs_start(vector<int>& rows) {
  int state = encode(rows);
  vis_start[state] = true;
  int turn = (accumulate(rows.begin(), rows.end(), 0) & 1) + 1;
  for (int i = 0; i < 7; ++i) {
    if (rows[i] != 6 && a[i][rows[i]] == turn) {
      int next_state = state + pot7[i];
      if (!vis_start[next_state]) {
        ++rows[i];
        dfs_start(rows);
        --rows[i];
      }
    }
  }
}

bool vis_end[7*7*7*7*7*7*7];
void dfs_end(vector<int>& rows) {
  int state = encode(rows);
  vis_end[state] = true;
  int turn = ((accumulate(rows.begin(), rows.end(), 0) - 1) & 1) + 1;
  for (int i = 0; i < 7; ++i) {
    if (rows[i] && a[i][rows[i] - 1] == turn) {
      int next_state = state - pot7[i];
      if (!vis_end[next_state]) {
        --rows[i];
        dfs_end(rows);
        ++rows[i];
      }
    }
  }
}

int row(vector<int>& rows, int i, int j) {
  bool ok = 1;
  for (int k = i + 1; k <= i + 3; ++k) {
    if (rows[k] <= j || a[k][j] != a[i][j]) {
      ok = 0;
      break;
    }
  }
  return ok ? a[i][j] : 0;
}

int diagonal_up(vector<int>& rows, int i, int j) {
  bool ok = 1;
  for (int k = i + 1; k <= i + 3; ++k) {
    int jj = j + k - i;
    if (rows[k] <= jj || a[k][jj] != a[i][j]) {
      ok = 0;
      break;
    }
  }
  return ok ? a[i][j] : 0;
}

int diagonal_down(vector<int>& rows, int i, int j) {
  bool ok = 1;
  for (int k = i + 1; k <= i + 3; ++k) {
    int jj = j + i - k;
    if (rows[k] <= jj || a[k][jj] != a[i][j]) {
      ok = 0;
      break;
    }
  }
  return ok ? a[i][j] : 0;
}

int column(vector<int>& rows, int i, int j) {
  bool ok = a[i][j] == a[i][j - 1] && a[i][j] == a[i][j - 2] && a[i][j] == a[i][j - 3];
  return ok ? a[i][j] : 0;
}

int winners(int state) {
  vector<int> rows = decode(state);
  int w = 0;
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < rows[i]; ++j) {
      if (j >= 3) {
        w |= column(rows, i, j);
      }
      if (i <= 3) {
        w |= row(rows, i, j);
        if (j <= 3) {
          w |= diagonal_up(rows, i, j);
        }
        if (j >= 3) {
          w |= diagonal_down(rows, i, j);
        }
      }
    }
  }
  return w;
}

void solve() {
  int aux_a[6][7];
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 7; ++j) {
      char c;
      cin >> c;
      aux_a[i][j] = (c == 'F') + 1;
    }
  }
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 7; ++j) {
      a[j][5 - i] = aux_a[i][j];
    }
  }
  memset(vis_start, 0, sizeof vis_start);
  memset(vis_end, 0, sizeof vis_end);
  {
    vector<int> rows = {0, 0, 0, 0, 0, 0, 0};
    dfs_start(rows);
    rows = {6, 6, 6, 6, 6, 6, 6};
    dfs_end(rows);
  }
  int can_win = 0;
  for (int i = 0; i < pot7[6] * 7; ++i) {
    if (vis_start[i] && vis_end[i]) {
      int w = winners(i);
      if (w != 3) {
        can_win |= w;
      }
    }
  }
  cout << "0CF?"[can_win] << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  pot7[0] = 1;
  for (int i = 1; i < 7; ++i) pot7[i] = pot7[i - 1] * 7;

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}