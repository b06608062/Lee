class Solution {
public:
  int longestBalanced(vector<int> &nums) {
    int n = nums.size();

    int res = 0;
    unordered_set<int> odd, even;
    for (int i = 0; i < n; ++i) {
      odd.clear();
      even.clear();
      for (int j = i; j < n; ++j) {
        int x = nums[j];
        if (x % 2)
          odd.insert(x);
        else
          even.insert(x);
        if (odd.size() == even.size())
          res = max(res, j - i + 1);
      }
    }

    return res;
  }
};