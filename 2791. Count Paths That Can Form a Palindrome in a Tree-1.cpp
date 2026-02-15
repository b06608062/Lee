// mark
// 2677
// 狀態壓縮 + 兩數異或 + LCA + 哈希前綴累計
// 1. 利用 (1 << char) 記錄路徑字元奇偶性，異或運算(XOR)實現奇偶抵消
// 2. 樹上路徑異或性質：Path(u, v) = Path(root, u) ^ Path(root, v)
// 3. 轉化為 Two Sum 問題：在 map 中尋找 x ^ target = 0 或 x ^ target = 2^k

class Solution {
public:
  vector<vector<int>> adj;
  unordered_map<int, long long> umap;
  long long res = 0;
  long long countPalindromePaths(vector<int> &parent, string s) {
    int n = parent.size();

    adj.resize(n);
    for (int i = 1; i < n; ++i) {
      int p = parent[i];
      adj[p].push_back(i);
    }

    umap[0] = 1;
    dfs(s, 0, 0);

    return res;
  }

  void dfs(string &s, int u, int xor_) {
    for (auto v : adj[u]) {
      int x = xor_ ^ (1 << s[v] - 'a');
      res += umap[x];
      for (int i = 0; i < 26; ++i)
        res += umap[x ^ (1 << i)];
      umap[x]++;
      dfs(s, v, x);
    }
  }
};