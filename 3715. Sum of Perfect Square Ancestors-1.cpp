const int MX = 100001;
int core[MX];

auto init = [] {
  for (int i = 1; i < MX; ++i)
    if (core[i] == 0)
      for (int j = 1; j < sqrt(MX / i); ++j)
        core[i * j * j] = i;
  return 0;
}();

class Solution {
public:
  long long sumOfAncestors(int n, vector<vector<int>> &edges,
                           vector<int> &nums) {
    vector adj(n, vector<int>());
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    unordered_map<int, long long> umap;
    long long res = 0;

    auto dfs = [&](this auto &&dfs, int u, int parent) -> void {
      int c = core[nums[u]];
      res += umap[c];
      umap[c]++;
      for (auto v : adj[u])
        if (v != parent)
          dfs(v, u);
      umap[c]--;
    };

    dfs(0, -1);

    return res;
  }
};