class Solution {
public:
  string foreignDictionary(vector<string> &words) {
    int n = words.size();

    vector<vector<int>> adj(26);
    bool edge[26][26] = {false};
    int indeg[26] = {0};
    bool appear[26] = {false};

    for (auto &w : words)
      for (char c : w)
        appear[c - 'a'] = true;

    for (int i = 0; i < n - 1; ++i) {
      string &s = words[i];
      string &t = words[i + 1];
      int len_s = s.size(), len_t = t.size();
      int m = min(len_s, len_t);
      int j = 0;
      while (j < m && s[j] == t[j])
        ++j;

      if (j == m) {
        if (len_s > len_t)
          return "";
        continue;
      }

      int u = s[j] - 'a';
      int v = t[j] - 'a';
      if (!edge[u][v]) {
        edge[u][v] = true;
        adj[u].push_back(v);
        indeg[v]++;
      }
    }

    queue<int> q;
    int totalChars = 0;
    for (int i = 0; i < 26; ++i)
      if (appear[i]) {
        totalChars++;
        if (indeg[i] == 0)
          q.push(i);
      }

    string res;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      res.push_back(u + 'a');
      for (int v : adj[u])
        if (--indeg[v] == 0)
          q.push(v);
    }

    if (res.size() != totalChars)
      return "";

    return res;
  }
};
