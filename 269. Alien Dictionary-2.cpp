class Solution {
public:
  string foreignDictionary(vector<string> &words) {
    int n = words.size();

    vector<vector<int>> adj(26);
    bool edge[26][26] = {false};
    int indeg[26] = {0};
    bool appear[26] = {false};

    for (auto &w : words)
      for (auto &ch : w)
        appear[ch - 'a'] = true;

    for (int i = 0; i < n - 1; ++i) {
      string &s = words[i], &t = words[i + 1];
      int s_l = s.size(), t_l = t.size();
      int m = min(s_l, t_l);
      int j = 0;
      while (j < m && s[j] == t[j])
        ++j;
      if (j == m) {
        if (s_l > t_l)
          return "";
        continue;
      }
      int u = s[j] - 'a';
      int v = t[j] - 'a';
      if (!edge[u][v]) {
        adj[u].push_back(v);
        edge[u][v] = true;
        indeg[v]++;
      }
    }

    queue<int> q;
    int total = 0;
    for (int i = 0; i < 26; ++i) {
      if (appear[i]) {
        total++;
        if (indeg[i] == 0)
          q.push(i);
      }
    }

    string res;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      res.push_back(u + 'a');
      for (auto v : adj[u])
        if (--indeg[v] == 0)
          q.push(v);
    }

    return res.size() == total ? res : "";
  }
};