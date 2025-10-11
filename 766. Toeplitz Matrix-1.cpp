class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    unordered_map<int, int> umap;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (umap.count(i - j) && umap[i - j] != matrix[i][j])
          return false;
        else
          umap[i - j] = matrix[i][j];

    return true;
  }
};