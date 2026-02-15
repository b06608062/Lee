class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          vis[i][j] = 1;
          q.push({i, j});
        }
      }
    }

    int step = 0;
    while (!q.empty()) {
      step++;
      int sz = q.size();
      while (sz--) {
        auto [ui, uj] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int vi = ui + dirs[k], vj = uj + dirs[k + 1];
          if (vi < 0 || vi >= m || vj < 0 || vj >= n || vis[vi][vj])
            continue;
          vis[vi][vj] = 1;
          mat[vi][vj] = step;
          q.push({vi, vj});
        }
      }
    }

    return mat;
  }
};