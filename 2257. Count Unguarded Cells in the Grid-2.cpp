class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    vector<vector<int>> state(m, vector<int>(n, 0));
    vector<vector<bool>> guarded(m, vector<bool>(n, false));

    for (auto &g : guards)
      state[g[0]][g[1]] = 1;
    for (auto &w : walls)
      state[w[0]][w[1]] = 2;

    for (int i = 0; i < m; i++) {
      bool seen = false;
      for (int j = 0; j < n; j++) { // left → right
        if (state[i][j] == 1)
          seen = true;
        else if (state[i][j] == 2)
          seen = false;
        else if (seen)
          guarded[i][j] = true;
      }
      seen = false;
      for (int j = n - 1; j >= 0; j--) { // right → left
        if (state[i][j] == 1)
          seen = true;
        else if (state[i][j] == 2)
          seen = false;
        else if (seen)
          guarded[i][j] = true;
      }
    }

    for (int j = 0; j < n; j++) {
      bool seen = false;
      for (int i = 0; i < m; i++) {
        if (state[i][j] == 1)
          seen = true;
        else if (state[i][j] == 2)
          seen = false;
        else if (seen)
          guarded[i][j] = true;
      }
      seen = false;
      for (int i = m - 1; i >= 0; i--) {
        if (state[i][j] == 1)
          seen = true;
        else if (state[i][j] == 2)
          seen = false;
        else if (seen)
          guarded[i][j] = true;
      }
    }

    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (state[i][j] == 0 && !guarded[i][j])
          res++;

    return res;
  }
};
