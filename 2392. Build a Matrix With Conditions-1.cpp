class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    vector<vector<int>> adj_r(k + 1);
    vector<int> indeg_r(k + 1, 0);
    vector<vector<bool>> appear_r(k + 1, vector<bool>(k + 1, false));
    for (auto &r : rowConditions) {
      int u = r[0], v = r[1];
      if (!appear_r[u][v]) {
        appear_r[u][v] = true;
        adj_r[u].push_back(v);
        indeg_r[v]++;
      }
    }

    queue<int> q_r;
    for (int i = 1; i <= k; ++i)
      if (indeg_r[i] == 0)
        q_r.push(i);

    vector<int> row;
    while (!q_r.empty()) {
      int u = q_r.front();
      q_r.pop();
      row.push_back(u);
      for (auto v : adj_r[u])
        if (--indeg_r[v] == 0)
          q_r.push(v);
    }
    if (row.size() != k)
      return {};

    vector<vector<int>> adj_c(k + 1);
    vector<int> indeg_c(k + 1, 0);
    vector<vector<bool>> appear_c(k + 1, vector<bool>(k + 1, false));
    for (auto &c : colConditions) {
      int u = c[0], v = c[1];
      if (!appear_c[u][v]) {
        appear_c[u][v] = true;
        adj_c[u].push_back(v);
        indeg_c[v]++;
      }
    }

    queue<int> q_c;
    for (int i = 1; i <= k; ++i)
      if (indeg_c[i] == 0)
        q_c.push(i);

    vector<int> col;
    while (!q_c.empty()) {
      int u = q_c.front();
      q_c.pop();
      col.push_back(u);
      for (auto v : adj_c[u])
        if (--indeg_c[v] == 0)
          q_c.push(v);
    }
    if (col.size() != k)
      return {};

    unordered_map<int, int> idx_r, idx_c;
    for (int i = 0; i < k; ++i) {
      idx_r[row[i]] = i;
      idx_c[col[i]] = i;
    }

    vector<vector<int>> res(k, vector<int>(k, 0));
    for (int i = 1; i <= k; ++i)
      res[idx_r[i]][idx_c[i]] = i;

    return res;
  }
};