class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> f(m, vector<int>(n, 0));

    f[0][0] = 1;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i > 0)
          f[i][j] += f[i - 1][j];
        if (j > 0)
          f[i][j] += f[i][j - 1];
      }

    return f[m - 1][n - 1];
  }
};

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> f(m, vector<int>(n, 0));
    f[0][0] = 1;
    for (int i = 1; i < m; ++i)
      f[i][0] = 1;
    for (int j = 1; j < n; ++j)
      f[0][j] = 1;
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        f[i][j] = f[i - 1][j] + f[i][j - 1];
    return f[m - 1][n - 1];
  }
};

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    f[0][1] = 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        f[i][j] = f[i - 1][j] + f[i][j - 1];
    return f[m][n];
  }
};

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    f[1][1] = 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        f[i][j] += f[i - 1][j] + f[i][j - 1];
    return f[m][n];
  }
};

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m < n)
      return uniquePaths(n, m);
    vector<int> f(n, 1);
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        f[j] += f[j - 1];

    return f[n - 1];
  }
};

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m < n)
      return uniquePaths(n, m);
    vector<int> f(n, 1);
    for (int i = 1; i < m; ++i) {
      vector<int> nxt_f(n);
      nxt_f[0] = f[0];
      for (int j = 1; j < n; ++j) {
        nxt_f[j] = nxt_f[j - 1] + f[j];
      }
      f.swap(nxt_f);
    }

    return f[n - 1];
  }
};