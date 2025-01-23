#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct AhoCorasick {
  enum { alpha = 26,
         first = 'a' };
  struct Node {
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
    bool vis;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vector<int> backp;
  void insert(string& s, int j) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int& m = N[n].next[c - first];
      if (m == -1) {
        n = m = (int)N.size();
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  AhoCorasick(vector<string>& pat) : N(1, -1) {
    for (int i = 0; i < (int)pat.size(); ++i)
      insert(pat[i], i);
    N[0].back = (int)N.size();
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; ++i) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }
  vector<int> process(string word, int p) {
    vector<int> ans(p, -1);
    int n = 0;
    for (int i = 0; i < (int)word.size(); ++i) {
      n = N[n].next[word[i] - first];
      dfs(N[n].end, i + 1, ans);
    }
    return ans;
  }
  void dfs(int k, int pos, vector<int>& ans) {
    if (k == -1 || ans[k] != -1) {
      return;
    }
    ans[k] = pos;
    dfs(backp[k], pos , ans);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  int n;
  cin >> s >> n;

  vector<string> pat(n);
  for (string& p: pat) {
    cin >> p;
  }

  AhoCorasick aho(pat);

  vector<int> ans = aho.process(s, n);

  for (int i = 0; i < n; ++i) {
    if (ans[i] != -1) {
      ans[i] += 1 - (int)pat[i].size();
    }
    cout << ans[i] << '\n';
  }

  return 0;
}