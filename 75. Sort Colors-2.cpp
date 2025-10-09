class Solution {
public:
  void sortColors(vector<int> &nums) {
    int cnt[3] = {0};
    for (auto x : nums)
      cnt[x]++;

    int idx = 0;
    for (int i = 0; i <= 2; ++i)
      while (cnt[i]--)
        nums[idx++] = i;
  }
};