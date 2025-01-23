#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n;
  cin >> n;

  vector<string> adj(n);
  for (string& row : adj) {
    cin >> row;
  }

  oset<int> ost;
  for (int i = 0; i < n; ++i) {
    ost.insert(i);
  }

  vector<int> p(n);
  for (int i = n - 1; i >= 0; --i) {
    int cnt = 0;
    for (int j = 0; j < i; ++j) {
      cnt += adj[i][j] == '1';
    }
    auto it = ost.find_by_order(cnt);
    p[*it] = i + 1;
    ost.erase(it);
  }

  for (int x : p) {
    cout << x << ' ';
  }
  cout << '\n';
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