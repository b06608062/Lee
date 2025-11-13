class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int l = 1, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      int cnt = 0;
      for (auto x : nums)
        if (x <= m)
          cnt++;
      if (cnt <= m)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};