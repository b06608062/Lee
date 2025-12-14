class Solution {
public:
  vector<int> rowAndMaximumOnes(vector<vector<int>> &mat) {
    int m = mat.size();

    int row = -1, cnt = -1;
    for (int i = 0; i < m; ++i) {
      int cur = 0;
      for (auto x : mat[i])
        cur += x;
      if (cur > cnt) {
        cnt = cur;
        row = i;
      }
    }

    return {row, cnt};
  }
};