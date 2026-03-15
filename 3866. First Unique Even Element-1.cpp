class Solution {
public:
  int firstUniqueEven(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    for (auto x : nums)
      cnt[x]++;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (x % 2 == 0 && cnt[x] == 1)
        return x;
    }
    return -1;
  }
};