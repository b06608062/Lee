class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    auto row = helper(k, rowConditions);
    if (row.empty())
      return {};
    auto col = helper(k, colConditions);
    if (col.empty())
      return {};
    vector<vector<int>> res(k, vector<int>(k, 0));
    for (int i = 1; i <= k; ++i)
      res[row[i]][col[i]] = i;
    return res;
  }

  unordered_map<int, int> helper(int k, vector<vector<int>> &conditions) {
    vector<vector<int>> adj(k + 1);
    vector<int> ind(k + 1, 0);
    for (auto &condition : conditions) {
      int u = condition[0], v = condition[1];
      adj[u].push_back(v);
      ind[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= k; ++i)
      if (ind[i] == 0)
        q.push({i});

    vector<int> res;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      res.push_back(u);
      for (auto v : adj[u])
        if (--ind[v] == 0)
          q.push(v);
    }

    if (res.size() != k)
      return {};

    unordered_map<int, int> umap;
    for (int i = 0; i < k; ++i)
      umap[res[i]] = i;

    return umap;
  }
};