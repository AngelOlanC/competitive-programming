#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

bool sweep_from_left(vector<vector<bool>>& has_point, int& ans, int& cnt_pts) {
  bool change = false;
  for (int x = 0; x < 1000; ++x) {
    if (cnt_pts == 1) {
      break;
    }
    int carry = 0;
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y]) {
        ++carry;
      }
    }
    if (carry > 1) {
      break;
    }
    if (!carry) {
      continue;
    }
    change = true;
    ++ans;
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y]) {
        if (has_point[x + 1][y]) {
          --cnt_pts;
        }
        has_point[x][y] = false;
        has_point[x + 1][y] = true;
      }
    }
  }
  return change;
}

bool sweep_from_right(vector<vector<bool>>& has_point, int& ans, int& cnt_pts) {
  bool change = false;
  for (int x = 1000; x >= 1; --x) {
    if (cnt_pts == 1) {
      break;
    }
    int carry = 0;
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y]) {
        ++carry;
      }
    }
    if (carry > 1) {
      break;
    }
    if (!carry) {
      continue;
    }
    change = true;
    ++ans;
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y]) {
        if (has_point[x - 1][y]) {
          --cnt_pts;
        }
        has_point[x][y] = false;
        has_point[x - 1][y] = true;
      }
    }
  }
  return change;
}

bool sweep_from_up(vector<vector<bool>>& has_point, int& ans, int& cnt_pts) {
  bool change = false;
  for (int y = 0; y < 1000; ++y) {
    if (cnt_pts == 1) {
      break;
    }
    int carry = 0;
    for (int x = 0; x <= 1000; ++x) {
      if (has_point[x][y]) {
        ++carry;
      }
    }
    if (carry > 1) {
      break;
    }
    if (!carry) {
      continue;
    }
    change = true;
    ++ans;
    for (int x = 0; x <= 1000; ++x) {
      if (has_point[x][y]) {
        if (has_point[x][y + 1]) {
          --cnt_pts;
        }
        has_point[x][y] = false;
        has_point[x][y + 1] = true;
      }
    }
  }
  return change;
}

bool sweep_from_down(vector<vector<bool>>& has_point, int& ans, int& cnt_pts) {
  bool change = false;
  for (int y = 1000; y >= 1; --y) {
    if (cnt_pts == 1) {
      break;
    }
    int carry = 0;
    for (int x = 0; x <= 1000; ++x) {
      if (has_point[x][y]) {
        ++carry;
      }
    }
    if (carry > 1) {
      break;
    }
    if (!carry) {
      continue;
    }
    change = true;
    ++ans;
    for (int x = 0; x <= 1000; ++x) {
      if (has_point[x][y]) {
        if (has_point[x][y - 1]) {
          --cnt_pts;
        }
        has_point[x][y] = false;
        has_point[x][y - 1] = true;
      }
    }
  }
  return change;
}

int cnt_points(vector<vector<bool>>& has_point) {
  int cnt = 0;
  for (int x = 0; x <= 1000; ++x) {
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y]) {
        ++cnt;
      }
    }
  }
  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vector<bool>> has_point(1001, vector<bool>(1001));
  for (int i = 0; i < 5; ++i) {
    int x, y;
    cin >> x >> y;
    has_point[x][y] = true;
  }

  int ans = 0, cnt_pts = 5;
  while (sweep_from_left(has_point, ans, cnt_pts) || sweep_from_right(has_point, ans, cnt_pts)
      || sweep_from_up(has_point, ans, cnt_pts) || sweep_from_down(has_point, ans, cnt_pts)) {
  }

  int mn_x = 1000, mx_x = 0, mn_y = 1000, mx_y = 0;
  for (int x = 0; x <= 1000; ++x) {
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y]) {
        mn_x = min(mn_x, x);
        mx_x = max(mx_x, x);
        mn_y = min(mn_y, y);
        mx_y = max(mx_y, y);
      }
    }
  }

  if (mn_x == mx_x) {
    ans += mx_y - mn_y;
    cout << ans << '\n';
    return 0;
  }
  
  if (mn_y == mx_y) {
    ans += mx_x - mn_x;
    cout << ans << '\n';
    return 0;
  }

  ans += 2 * (mx_x - mn_x) + 2 * (mx_y - mn_y);

  for (int x = 0; x <= 1000; ++x) {
    for (int y = 0; y <= 1000; ++y) {
      if (has_point[x][y] && x > mn_x && x < mx_x && y > mn_y && y < mx_y) {
        ans += min(mx_x - mn_x, mx_y - mn_y);
        break;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}