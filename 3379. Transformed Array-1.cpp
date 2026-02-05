class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (x == 0) {
        res[i] = nums[i];
      } else {
        res[i] = nums[((i + x) % n + n) % n];
      }
    }

    return res;
  }
};