#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct AhoCorasick {
  enum { alpha = 256,
         first = 0 };
  struct Node {
    int back, next[alpha], start = -1, end = -1, nmatches = 0;
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
  vector<int> find(string word) {
    int n = 0;
    vector<int> res;
    for (char c : word) {
      n = N[n].next[c - first];
      res.push_back(N[n].end);
    }
    return res;
  }
  vector<vector<int>> findAll(vector<string>& pat, string word) {
    vector<int> r = find(word);
    vector<vector<int>> res((int)pat.size());
    for (int i = 0; i < (int)word.size(); ++i) {
      int ind = r[i];
      while (ind != -1) {
        res[ind].push_back(i);
        ind = backp[ind];
      }
    }
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  while (cin >> n) {
    string xd;
    getline(cin, xd);

    vector<string> pat(n);
    for (string& p : pat) {
      getline(cin, p);
    }
    string s;
    getline(cin, s);

    AhoCorasick aho(pat);
    vector<vector<int>> occ = aho.findAll(pat, s);
    for (int i = 0; i < n; ++i){
      for (int j : occ[i]) {
        cout << j - (int)pat[i].size() + 1 << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}