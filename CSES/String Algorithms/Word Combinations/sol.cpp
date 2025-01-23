#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

struct Trie {
  struct Node {
    map<char, int> e;
    bool isEnd;

    Node() : isEnd(false) {}
  };

  vector<Node> v;

  Trie() : v(1) {}

  void insert(string s) {
    int u = 0;
    for (char c : s) {
      if (v[u].e.find(c) == v[u].e.end()) {
        v[u].e[c] = (int)v.size();
        v.emplace_back();
      }
      u = v[u].e[c];
    }
    v[u].isEnd = true;
  }

  int dp(int i, string& s, vector<int>& memo) {
    if (i == (int)s.size()) {
      return 1;
    }
    int& ans = memo[i];
    if (ans != -1) {
      return ans;
    }
    ans = 0;
    int u = 0;
    for (int j = i; j < (int)s.size() && v[u].e.find(s[j]) != v[u].e.end(); ++j) {
      u = v[u].e[s[j]];
      if (v[u].isEnd) {
        ans = add(ans, dp(j + 1, s, memo));
      }
    }
    return ans;
  }
  int dp(string& s) {
    vector<int> memo((int)s.size(), -1);
    return dp(0, s, memo);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int n;
  cin >> n;

  Trie trie;
  while (n--) {
    string t;
    cin >> t;
    trie.insert(t);
  }

  cout << trie.dp(s) << '\n';

  return 0;
}