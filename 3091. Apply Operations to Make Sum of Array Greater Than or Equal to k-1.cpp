class Solution {
public:
  int minOperations(int k) {
    int res = INT_MAX;
    int sqrtK = sqrt(k);
    for (int i = 1; i <= sqrtK; ++i)
      res = min(res, (i - 1) + ((k + i - 1) / i - 1));

    return res;
  }
};