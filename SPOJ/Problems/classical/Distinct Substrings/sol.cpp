#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct Trie {
  struct Node {
    map<char, int> adj;
  };

  vector<Node> trie;

  Trie() : trie(1) {}

  void add(string s) {
    int u = 0;
    for (auto &c : s) {
      if (!trie[u].adj.count(c)) {
        trie[u].adj[c] = (int)trie.size();
        trie.emplace_back();
      }
      u = trie[u].adj[c];
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    
    Trie t;
    for (int i = 0; i < (int)s.size(); ++i) {
      t.add(s.substr(i));
    }
    cout << (int)t.trie.size() - 1 << '\n';
  }

  return 0;
}