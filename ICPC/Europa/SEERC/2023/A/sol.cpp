#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

inline bool on(i64 x, int b) {
  return (x >> b) & 1;
}

struct DSU {
  vector<int> e;
  DSU(int n) : e(n, -1) {}
  int get(int x) {
    return e[x] < 0 ? x : e[x] = get(e[x]);
  }
  void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return;
    }
    if (e[x] > e[y]) {
      swap(x, y);
    }
    e[x] += e[y];
    e[y] = x;
  }
};

void toposort(vector<i64> anc, vector<int>& order) {
  int n = (int)anc.size();
  
  vector<int> deg(n);
  for (i64& x: anc) {
    for (int i = 0; i < n; ++i) {
      if (on(x, i)) {
        ++deg[i];
      }
    }
  }
  
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!deg[i]) {
      q.push(i);
    }
  }

  int t = n - 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    
    order[u] = t--;

    for (int v = 0; v < 40; ++v) {
      if (on(anc[u], v)) {
        --deg[v];
        if (!deg[v]) {
          q.push(v);
        }
      }
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  i64 all_and = (1ll << 40) - 1;
  vector<i64> in_all(40);
  for (int i = 0; i < n; ++i) {
    i64 x;
    cin >> x;
    all_and &= x;
    for (int j = 0; j < 40; ++j) {
      if (on(x, j)) {
        if (in_all[j]) {
          in_all[j] &= x;
        } else {
          in_all[j] = x;
        }
      }
    }
  }

  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  DSU dsu(40);
  for (int i = 0; i < 40; ++i) {
    for (int j = i + 1; j < 40; ++j) {
      if (on(in_all[i], j) && on(in_all[j], i)) {
        dsu.join(i, j); 
      }
    }
  }

  vector<i64> anc;
  {
    int curr_id = 0;
    vector<int> id(40, -1);
    for (int i = 0; i < 40; ++i) {
      if (!in_all[i]) {
        continue;
      }
      int p = dsu.get(i);
      if (id[p] == -1) {
        id[p] = curr_id++;
        anc.push_back(0);
      }
      for (int j = 0; j < 40; ++j) {
        if (i == j || !on(in_all[i], j) || on(in_all[j], i)) {
          continue;
        }
        // cout << i << " implica " << j << '\n';
        int p2 = dsu.get(j);
        if (id[p2] == -1) {
          id[p2] = curr_id++;
          anc.push_back(0);
        }
        anc[id[p]] |= 1ll << id[p2];
      }
    }
  }

  i64 ans = !all_and;
  int N = (int)anc.size(), L = N >> 1, R = N - L;

  vector<int> order(N);
  toposort(anc, order);

  vector<pair<int, i64>> anc2(N);
  for (int i = 0; i < N; ++i) {
    i64 new_msk = 0;
    for (int j = 0; j < 40; ++j) {
      if (on(anc[i], j)) {
        new_msk |= 1ll << order[j];
      }
    }
    anc2[i] = {order[i], new_msk};
  }
  sort(anc2.begin(), anc2.end());

  for (int i = 0; i < N; ++i) {
    anc[i] = anc2[i].second;
  }

  vector<int> sos(1 << L);
  for (int msk = 1; msk < (1 << L); ++msk) {
    i64 all = 0;
    for (int i = 0; i < L; ++i) {
      if (on(msk, i)) {
        all |= anc[i];
      }
    }

    bool ok = true;
    for (int i = 0; i < L; ++i) {
      if (on(msk, i) && on(all, i)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      // cout << "bien izquierda " << msk << '\n';
      ++ans;
      ++sos[msk];
    }
  }

  for (int i = 0; i < L; ++i) {
    for (int msk = 0; msk < (1 << L); ++msk) {
      if (on(msk, i)) {
        sos[msk] += sos[msk ^ (1 << i)];
      }
    }
  }

  for (int msk = 1; msk < (1 << R); ++msk) {
    i64 all = 0;
    for (int i = 0; i < R; ++i) {
      if (on(msk, i)) {
        all |= anc[L + i];
      }
    }

    bool ok = true;
    for (int i = 0; i < R; ++i) {
      if (on(msk, i) && on(all, L + i)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      // cout << "bien derecha " << msk << ' ' << all << ' ' << ((~all) & ((1 << L) - 1)) << ' ' << sos[(~all) & ((1 << L) - 1)] << '\n';
      ++ans;
      ans += sos[(~all) & ((1 << L) - 1)];
    }
  }

  cout << ans << '\n';

  return 0;
}