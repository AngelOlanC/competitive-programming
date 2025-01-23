#include <bits/stdc++.h> 
using namespace std;

vector<int> dfs(int l, int r, int k, vector<int>& ans, vector<int>& a, vector<int>& ind) {
  if (l + 1 == r) {
    return {a[l]};
  }
  
  int m = (l + r) >> 1;
  vector<int> left = dfs(l, m, k, ans, a, ind), right = dfs(m, r, k, ans, a, ind);
  
  vector<int> sorted(r - l);
  merge(left.begin(), left.end(), right.begin(), right.end(), sorted.begin());

  int len = r - l;
  for (int i = max(0, len - k - 1); i < len; ++i) {
    if (sorted[i] >= r - l) {
      ++ans[ind[sorted[i]]];
    }
  }
  return sorted;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  
  vector<int> a(1 << n), ind((1 << n) + 1);
  for (int i = 0; i < (int)a.size(); ++i) {
    cin >> a[i];
    ind[a[i]] = i;
  }

  vector<int> ans(1 << n);
  dfs(0, 1 << n, k, ans, a, ind);

  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}