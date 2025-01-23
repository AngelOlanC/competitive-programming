#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef set<ll> sll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}
#define inf 1e17
#define pb(x) push_back(x)
#define rep(i, x,n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define fo(x) find_by_order(x)
#define ok(x) order_of_key(x)
const ll mod = 998244353;

ll calc(vi &nums) {
    set<int> st, nx(all(nums));
    while (nx.size() > st.size()) {
        st = nx;
        for (auto x : st)
        for (auto y : st)
            nx.insert(x & y), nx.insert(x | y);
    }

    return nx.size();
}

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

  int t = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    
    order[u] = n - t - 1;
    ++t;

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

int mycalc(vector<int> arr) {
  int n = (int)arr.size();
  i64 all_and = (1ll << 40) - 1;
  vector<i64> in_all(40);
  for (i64 x : arr) {
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
    return 1;
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

  vector<pair<int, int>> anc2(N);
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
      // cout << "bien derecha " << all << ' ' << ((~all) & ((1 << L) - 1)) << ' ' << sos[(~all) & ((1 << L) - 1)] << '\n';
      ++ans;
      ans += sos[(~all) & ((1 << L) - 1)];
    }
  }
  return ans;
}

void solve() {
    int n = 20;
    for (int mask = 1; mask < (1 << n); mask++) {
        vi nums;
        rep(i, 0, n)
            if (mask & (1 << i))
                nums.pb(i);
        int r1 = calc(nums), r2 = mycalc(nums);
        if (r1 != r2) {
          cout << "Error en caso ";
          for (int x :nums) {
            cout << x << ' ';
          }
          cout << '\n';
          cout << "La respuesta es " << r1 << " pero se regresó " << r2 << '\n';
          exit(0);
        }
        cout << "pasa " << mask << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    cout << "Todo bien\n";
    return 0;
}