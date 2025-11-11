class Solution {
public:
  vector<int> grayCode(int n) {
    if (n == 0)
      return {0};

    vector<int> res = {0, 1};
    for (int i = 1; i < n; ++i) {
      int l = 1 << i;
      for (int j = l - 1; j >= 0; --j)
        res.push_back(res[j] | 1 << i);
    }

    return res;
  }
};