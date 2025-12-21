// mark
// 1876
// Greedy + 字串字典 + 前綴狀態追蹤
class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int n = strs.size(), m = strs[0].size();

    vector<bool> valid(n, false);

    int res = 0;
    for (int j = 0; j < m; ++j) {
      bool flag = false;
      auto temp = valid;
      for (int i = 0; i < n - 1; ++i)
        if (temp[i])
          continue;
        else if (strs[i][j] < strs[i + 1][j])
          temp[i] = 1;
        else if (strs[i][j] > strs[i + 1][j]) {
          flag = true;
          break;
        }
      if (flag)
        res++;
      else
        valid = temp;
    }

    return res;
  }
};