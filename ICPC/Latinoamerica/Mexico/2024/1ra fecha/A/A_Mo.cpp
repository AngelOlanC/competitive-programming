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

#define N 10010

ll a[N];
map<ll, ll> diff, values;

void add(int idx, int end) { 
  if (values[a[idx]]) { 
    diff[0] += values[a[idx]];
  } 
  values[a[idx]]++;
  auto it = values.find(a[idx]);
  auto it2 = it;
  if (it2 != values.begin()) {
    it2--;
    diff[abs(a[idx] - it2->first)] += it2->second;
  }
  it2 = it;
  if (it2 != values.end()) {
    it2++;
    diff[abs(it2->first - a[idx])] += it2->second;
  }
}  // add a[idx] (end = 0 or 1)
void del(int idx, int end) {
  auto drop = [&](int x) -> void {
    if (!diff[x]) {
      diff.erase(x);
    }
  };

  diff[0] -= values[a[idx]] - 1;
  drop(0);

  auto it = values.find(a[idx]);
  auto it2 = it;
  if (it2 != values.begin()) {
    it2--;
    int d = abs(a[idx] - it2->first);
    diff[d] -= it2->second;
    drop(d);
  }
  it2 = it;
  if (it2 != values.end()) {
    it2++;
    int d = abs(it2->first - a[idx]);
    diff[d] -= it2->second;
    drop(d);
  }

  it2 = it;
  if (it != values.begin() && it2 != values.end()) {
    auto it3 = it;
    it3--;
    it2++;
    int d = abs(it2->first - it3->first);
    diff[d] += it3->second * it2->second;
  }
  values[a[idx]]--;
  if (!values[a[idx]]) {
    values.erase(a[idx]);
  }
}  // remove a[idx]
int calc(){
  return diff.begin()->first;
}                     // compute current answer

vi mosAlgo(vector<pi> Q) {
  int L = 0, R = 0, blk = 32;  // IMPORTANT!! blk ~= N/sqrt(Q)
  vi s(SZ(Q)), res = s;
#define K(x) pi(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    pi q = Q[qi];
    while (L > q.first) add(--L, 0);
    while (R < q.second) add(R++, 1);
    while (L < q.first) del(L++, 0);
    while (R > q.second) del(--R, 1);
    res[qi] = calc();
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  FOR (i, 0, n) {
    cin >> a[i];
  }

  int q;
  cin >> q;
  vector<pi> quer(q);
  FOR (i, 0, q) {
    cin >> quer[i].first >> quer[i].second;
    quer[i].first--;
  }

  vi ans = mosAlgo(quer);
  for (auto &x : ans) {
    cout << x << ENDL;
  }

  return 0;
}