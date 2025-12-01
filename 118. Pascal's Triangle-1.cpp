class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    res.push_back({1});
    if (numRows == 1)
      return res;

    for (int i = 1; i < numRows; ++i) {
      int sz = i + 1;
      vector<int> level(sz, 1);
      for (int j = 1; j < sz - 1; ++j)
        level[j] = res[i - 1][j - 1] + res[i - 1][j];
      res.push_back(level);
    }

    return res;
  }
};