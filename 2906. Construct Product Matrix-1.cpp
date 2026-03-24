class Solution {
public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid) {
    const int MOD = 12345;
    int n = grid.size(), m = grid[0].size();
    int sz = n * m;
    vector<int> arr;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        arr.push_back(grid[i][j] % MOD);

    vector<int> arr1(sz, 1);
    int prefix = 1;
    for (int i = 0; i < sz; ++i) {
      arr1[i] = prefix;
      prefix = (prefix * arr[i]) % MOD;
    }

    int suffix = 1;
    for (int i = sz - 1; i >= 0; --i) {
      arr1[i] = (arr1[i] * suffix) % MOD;
      suffix = (suffix * arr[i]) % MOD;
    }

    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < sz; i++)
      res[i / m][i % m] = arr1[i];

    return res;
  }
};