// mark
// ???
// 試填法 由高位到低位，嘗試把每一位都填 0，看看能不能滿足條件
// 如果不行，就把該位填 1，繼續往下一位

class Solution {
public:
  int minimumOR(vector<vector<int>> &grid) {
    int res = 0;
    for (int i = 20; i >= 0; --i) {
      int mask = res | ((1 << i) - 1);
      for (auto &row : grid) {
        bool find = false;
        for (auto x : row) {
          if ((x | mask) == mask) {
            find = true;
            break;
          }
        }
        if (!find) {
          res |= (1 << i);
          break;
        }
      }
    }
    return res;
  }
};