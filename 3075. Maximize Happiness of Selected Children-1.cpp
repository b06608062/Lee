class Solution {
public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    sort(happiness.rbegin(), happiness.rend());
    long long res = 0;
    for (int i = 0; i < k; ++i)
      res += max(happiness[i] - i, 0);

    return res;
  }
};