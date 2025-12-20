class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int m = strs.size(), n = strs[0].size();

    int res = 0;
    for (int c = 0; c < n; ++c)
      for (int r = 0; r < m - 1; ++r)
        if (strs[r][c] > strs[r + 1][c]) {
          res++;
          break;
        }

    return res;
  }
};