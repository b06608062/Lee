class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int m = bank.size(), n = bank[0].size();

    int cur = 0, prev = 0, res = 0;
    for (int i = 0; i < m; ++i) {
      cur = 0;
      for (int j = 0; j < n; ++j)
        if (bank[i][j] == '1')
          cur++;
      res += cur * prev;
      if (cur)
        prev = cur;
    }

    return res;
  }
};