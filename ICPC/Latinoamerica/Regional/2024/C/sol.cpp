#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
  vector<vector<int>> jmp;
  void init(const vector<int>& V) {
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= (int)V.size(); pw *= 2, ++k) {
      jmp.emplace_back((int)V.size() - pw * 2 + 1);
      for (int j = 0; j < (int)jmp[k].size(); ++j) {
        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
    }
  }
  int query(int l, int r) {
    if (l >= r) {
      return 1e9;
    }
    int dep = 31 - __builtin_clz(r - l);
    return min(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

int findC1(int L, int U, int rl, int R, vector<int>& r) {
  while (L + 1 < U) {
    int m = (L + U) >> 1;
    if (r[m] - rl <= R) {
      U = m;
    } else {
      L = m;
    }
  }
  return U;
}

int findC3(int L, int U, int bu, int B, vector<int>& b) {
  while (L + 1 < U) {
    int m = (L + U) >> 1;
    if (bu - b[m] <= B) {
      U = m;
    } else {
      L = m;
    }
  }
  return U;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int R, B;
  string S;
  cin >> R >> B >> S;

  int n = (int)S.size();
  vector<int> r(n + 1), b(n + 1);
  for (int i = 0; i < n; ++i) {
    r[i + 1] = r[i] + (S[i] == 'R');
    b[i + 1] = b[i] + (S[i] == 'B');
  }

  vector<vector<int>> aSt(16, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    aSt[1][i] = i - R;
    aSt[2][i] = R - r[i];
    aSt[3][i] = i - r[i];
    aSt[4][i] = -i - B;
    aSt[5][i] = -R - B;
    aSt[6][i] = R - r[i] - i - B;
    aSt[7][i] = -r[i] - B;
    aSt[8][i] = B + b[i];
    aSt[9][i] = i - R + B + b[i];
    aSt[10][i] = R - r[i] + B + b[i];
    aSt[11][i] = i - r[i] + B + b[i];
    aSt[12][i] = -i + b[i];
    aSt[13][i] = -R + b[i];
    aSt[14][i] = R - r[i] - i + b[i];
    aSt[15][i] = -r[i] + b[i];
  }

  vector<SparseTable> st(12);
  for (int i = 0; i < 12; ++i) {
    st[i].init(aSt[i]);
  }

  int q;
  cin >> q;
  while (q--) {
    int L, U;
    cin >> L >> U;
    --L;
    vector<int> c = {
      L + R,
      findC1(L, U, r[L], R, r),
      U - B,     
      findC3(L, U, b[U], B, b)
    };
    int ans = min({
      st[0].query(max({L, U - B, c[1], c[3]}))
    });
    cout << ans << '\n';
  }
}