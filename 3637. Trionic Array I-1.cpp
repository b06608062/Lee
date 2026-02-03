class Solution {
public:
  bool isTrionic(vector<int> &nums) {
    int n = nums.size();
    int stage = 0;
    for (int i = 1; i < n; ++i) {
      int x1 = nums[i - 1], x2 = nums[i];
      if (x1 == x2) {
        return false;
      } else if (stage == 0 && x2 < x1) {
        if (i == 1)
          return false;
        stage++;
      } else if (stage == 1 && x2 > x1) {
        stage++;
      } else if (stage == 2 && x2 < x1) {
        return false;
      }
    }

    return stage == 2;
  }
};