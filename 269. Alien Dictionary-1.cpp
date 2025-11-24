class Solution {
public:
  unordered_map<char, unordered_set<char>> adj;
  unordered_map<char, int> indeg;
  unordered_map<char, int> order;
  string foreignDictionary(vector<string> &words) {
    int n = words.size();

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        build(words[i], words[j]);

    queue<char> q;
    for (int i = 0; i < n; ++i) {
      string &w = words[i];
      for (auto ch : w)
        if (indeg.find(ch) == indeg.end()) {
          indeg[ch] = 0;
          q.push(ch);
        }
    }

    string res = "";
    while (!q.empty()) {
      char u = q.front();
      q.pop();
      res += u;
      for (auto v : adj[u]) {
        if (--indeg[v] == 0)
          q.push(v);
      }
    }

    for (auto [_, v] : indeg)
      if (v)
        return "";

    int sz = res.size();
    for (int i = 0; i < sz; ++i)
      order[res[i]] = i;

    for (int i = 0; i < n - 1; ++i)
      if (!valid(words[i], words[i + 1]))
        return "";

    return res;
  }

  void build(string &s, string &t) {
    int l = min(s.size(), t.size());
    for (int i = 0; i < l; ++i) {
      char si = s[i], ti = t[i];
      if (si != ti) {
        if (!adj[si].count(ti)) {
          adj[si].insert(ti);
          indeg[ti]++;
        }
        break;
      }
    }
  }

  bool valid(string &s, string &t) {
    int len_s = s.size();
    int len_t = t.size();
    int l = min(len_s, len_t);
    for (int i = 0; i < l; ++i)
      if (s[i] != t[i])
        return order[s[i]] < order[t[i]];
    return len_s <= len_t;
  }
};