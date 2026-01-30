// mark
// 2696
// APSP + 字符串 DP + 字典樹

class Solution {
public:
  struct TrieNode {
    bool isEnd;
    TrieNode *children[26];
  };

  TrieNode *root;

  void insert(string word) {
    TrieNode *ptr = root;
    for (char ch : word) {
      if (!ptr->children[ch - 'a'])
        ptr->children[ch - 'a'] = new TrieNode();
      ptr = ptr->children[ch - 'a'];
    }
    ptr->isEnd = true;
  }

  long long minimumCost(string source, string target, vector<string> &original,
                        vector<string> &changed, vector<int> &cost) {
    // APSP
    // str 2 str
    // dp
    const long long INF = LLONG_MAX / 2;
    int n = source.size(), m = original.size();
    unordered_map<string, int> s2i;
    vector<string> arr;
    int idx = 0;
    for (auto &s : original) {
      if (!s2i.count(s)) {
        s2i[s] = idx++;
        arr.push_back(s);
      }
    }
    for (auto &s : changed) {
      if (!s2i.count(s)) {
        s2i[s] = idx++;
        arr.push_back(s);
      }
    }
    int sz = arr.size();
    vector dist(sz, vector<long long>(sz, INF));
    for (int i = 0; i < sz; ++i) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
      int u = s2i[original[i]], v = s2i[changed[i]], c = cost[i];
      dist[u][v] = min(dist[u][v], 1ll * c);
    }

    for (int k = 0; k < sz; ++k) {
      for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    root = new TrieNode();
    for (auto &s : arr) {
      insert(s);
    }

    vector<long long> dp(n + 1, INF);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (source[i] == target[i]) {
        dp[i] = dp[i + 1];
      }
      TrieNode *ptr_s = root;
      TrieNode *ptr_t = root;
      string s = "", t = "";
      for (int j = i; j < n; ++j) {
        char chs = source[j], cht = target[j];
        if (!ptr_s->children[chs - 'a'] || !ptr_t->children[cht - 'a']) {
          break;
        }
        s += chs, t += cht;
        if (s2i.count(s) && s2i.count(t)) {
          int u = s2i[s], v = s2i[t];
          dp[i] = min(dp[i], dp[j + 1] + dist[u][v]);
        }
        ptr_s = ptr_s->children[chs - 'a'], ptr_t = ptr_t->children[cht - 'a'];
      }
    }

    return dp[0] == INF ? -1 : dp[0];
  }
};