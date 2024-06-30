#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int s[100005];
set<tuple<int, int, int>> st;

void process(int L, int R, int x) {
  auto it = st.lower_bound({L, 0, 0});
  vector<tuple<int, int, int>> intersected;
  while (it != st.end()) {
    auto [r, l, col] = *it;
    if (max(l, L) <= min(r, R)) {
      intersected.pb({l, r, col});
      it++;
    } else {
      break;
    }
  }

  for (auto &[l, r, col] : intersected) {
    auto it = tie(r, l, col);
    st.erase(it);

    s[col] -= min(R, r) - max(L, l) + 1;
    if (l < L) {
      st.insert({L - 1, l, col});
    }
    if (r > R) {
      st.insert({r, R + 1, col});
    }
  }
  s[x] += R - L + 1;
  st.insert({R, L, x});
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int l, c, n;
  cin >> l >> c >> n;

  st.insert({l - 1, 0, 0});
  s[0] = l;
  while (n--) {
    int p, x, A, B;
    cin >> p >> x >> A >> B;
    p--, x--;

    int L = (A + 1ll * s[p] * s[p] % l) % l;
    int R = (A + 1ll * (s[p] + B) * (s[p] + B) % l) % l;

    if (R < L) {
      swap(L, R);
    }
    
    process(L, R, x);
  }

  cout << *max_element(ALL(s)) << ENDL;

  return 0;
}