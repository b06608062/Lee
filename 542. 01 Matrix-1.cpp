class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();

    vector<vector<int>> res(m, vector<int>(n, 0));
    vector<int> dirs{0, 1, 0, -1, 0};

    using P = pair<int, int>;
    queue<P> q;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 0)
          q.push({i, j});

    int cur = 0;
    while (!q.empty()) {
      cur++;
      int sz = q.size();
      while (sz--) {
        auto [ui, uj] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int vi = ui + dirs[d], vj = uj + dirs[d + 1];
          if (vi >= 0 && vi < m && vj >= 0 && vj < n && mat[vi][vj] != 0) {
            mat[vi][vj] = 0;
            res[vi][vj] = cur;
            q.push({vi, vj});
          }
        }
      }
    }

    return res;
  }
};