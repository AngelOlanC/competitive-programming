#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void buildCartesianTree(vector<int>& b, vector<int>& l, vector<int>& r) {
  int prevMin = 0;
  stack<int> st;
  st.push(0);
  for (int i = 1; i < (int)b.size(); ++i) {
    while (!st.empty() && b[st.top()] > b[i]) {
      st.pop();
    }
    if (!st.empty()) {
      l[i] = r[st.top()];
      r[st.top()] = i;
    } else {
      l[i] = prevMin;
      prevMin = i;
    }
    st.push(i);
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    if (l[i] == -1) {
      l[i] = i;
    }
    if (r[i] == -1) {
      r[i] = i;
    }
  }
}

bool check(int x, vector<int>& b, vector<int>& l, vector<int>& r) {
  for (int i = 0; i < (int)b.size(); ++i) {
    if (gcd(b[l[i]] + x, b[r[i]] + x) % (b[i] + x)) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> b(n);
  for (int& x : b) {
    cin >> x;
  }

  int mn = *min_element(b.begin(), b.end()), mx = *max_element(b.begin(), b.end()), d = mx - mn;
  if (!d) {
    cout << k << ' ' << ((i64)k * (k + 1) >> 1) << '\n';
    return;
  }

  vector<int> div;
  for (int i = 1; i * i <= d; ++i) {
    if (d % i == 0) {
      div.push_back(i);
      if (i * i != d) {
        div.push_back(d / i);
      }
    }
  }

  vector<int> l(n, -1), r(n, -1);
  buildCartesianTree(b, l, r);

  int ans = 0;
  i64 sum = 0;
  for (int d : div) {
    if (d > mn) {
      int x = d - mn;
      if (x <= k && check(x, b, l, r)) {
        ++ans;
        sum += x;
      }
    }
  }
  cout << ans << ' ' << sum << '\n';
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