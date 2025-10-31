class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    int n = nums.size();
    n -= 2;

    vector<int> cnt(n, 0);

    vector<int> res;
    for (auto x : nums)
      if (++cnt[x] == 2)
        res.push_back(x);

    return res;
  }
};