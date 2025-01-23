#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using u64 = unsigned long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  const int BLOCK_SIZE = 64, BLOCKS = n / BLOCK_SIZE + 1;
  vector<vector<u64>> msks(n, vector<u64>(BLOCKS));

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '1') {
        msks[i][j / BLOCK_SIZE] |= 1ull << (j % BLOCK_SIZE);
      }
    }
  }

  vector<int> ans;
  for (int u = 0; u < n; ++u) {
    vector<u64> msk(BLOCKS);
    for (int i = 0; i < BLOCKS; ++i) {
      msk[i] = msks[u][i];
    }
    msk[u / BLOCK_SIZE] |= 1ull << (u % BLOCK_SIZE);
    
    for (int v = 0; v < n; ++v) {
      if ((msks[u][v / BLOCK_SIZE] >> (v % BLOCK_SIZE)) & 1) {
        for (int i = 0; i < BLOCKS; ++i) {
          msk[i] |= msks[v][i];
        }
      }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (!((msk[i / BLOCK_SIZE] >> (i % BLOCK_SIZE)) & 1)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.push_back(u);
      if ((int)ans.size() == 3) {
        break;
      }
    }
  }

  if ((int)ans.size() < 3) {
    cout << "NOT FOUND\n";
    return 0;
  }

  for (int u : ans) {
    cout << u + 1 << ' ';
  }
  cout << '\n';

  return 0;
}
