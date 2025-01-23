#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  
  --l;
  --r;
  
  vector<int> left, mid, right;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    if (i < l) {
      left.push_back(x);
    } else if (i > r) {
      right.push_back(x);
    } else {
      mid.push_back(x);
    }
  }

  sort(left.begin(), left.end());
  sort(mid.begin(), mid.end());
  sort(right.begin(), right.end());

  i64 s = accumulate(mid.begin(), mid.end(), 0ll), ns = s, aux = s;
  for (int p1 = 0, p2 = (int)mid.size() - 1; p1 < (int)left.size() && p2 >= 0 && left[p1] < mid[p2]; ++p1, --p2) {
    ns -= mid[p2];
    ns += left[p1];
  }
  s = min(s, ns);

  ns = aux;
  for (int p1 = 0, p2 = (int)mid.size() - 1; p1 < (int)right.size() && p2 >= 0 && right[p1] < mid[p2]; ++p1, --p2) {
    ns -= mid[p2];
    ns += right[p1];
  }
  s = min(s, ns);

  cout << s << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}