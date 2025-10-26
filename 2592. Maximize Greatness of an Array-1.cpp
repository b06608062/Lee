class Solution {
public:
  int maximizeGreatness(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int j = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      while (j < n && nums[j] <= nums[i])
        j++;
      if (j < n)
        res++;
      j++;
    }

    return res;
  }
};