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

// 0 -> left, 1 -> right
bool next_side(deque<pair<char, int>>& dq, int l, int r) { 
  if (l == r) return 1;
  auto [cf, tf] = dq[l];
  auto [cb, tb] = dq[r];
  if (r - l == 1) return cf < cb;
  if (cf != cb) return cf < cb;
  char cff = dq[l + 1].first, cbb = dq[r - 1].first;
  if (cff > cf && cbb > cf) {
    if (tf != tb) return tf > tb;
    return true;
  }
  if (cff < cf && cbb < cf) {
    if (tf != tb) return tf < tb;
    return next_side(dq, l + 1, r - 1);
  }
  return cff < cbb;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  deque<pair<char, int>> dq;
  {
    int t = 0;
    char lst = '#';
    FOR (i, 0, n){
      char c;
      cin >> c;
      if (c == lst) {
        ++t;
        continue;
      }
      dq.pb({lst, t});
      lst = c;
      t = 1;
    }
    dq.pb({lst, t});  
    dq.pop_front();
  }

  int print_cnt = 0;
  while (!dq.empty()) {
    bool side = next_side(dq, 0, SZ(dq) - 1);
    char c;
    int t;
    if (side) {
      c = dq.front().first;
      t = dq.front().second;
      dq.pop_front();
    } else {
      c = dq.back().first;
      t = dq.back().second;
      dq.pop_back();
    }
    while (t--) {
      cout << c;
      if (++print_cnt == 80) {
        cout << '\n';
        print_cnt = 0;
      }
    }
  }

  return 0;
}