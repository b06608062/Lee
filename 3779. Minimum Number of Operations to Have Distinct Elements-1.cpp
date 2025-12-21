class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();

    unordered_set<int> uset;

    int idx = -1;
    for (int i = n - 1; i >= 0; --i) {
      int x = nums[i];
      if (uset.count(x)) {
        idx = i;
        break;
      }
      uset.insert(x);
    }

    if (idx == -1)
      return 0;

    return idx / 3 + 1;
  }
};