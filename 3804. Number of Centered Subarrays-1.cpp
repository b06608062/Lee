class Solution {
public:
  int centeredSubarrays(vector<int> &nums) {
    int n = nums.size();

    int res = 0;
    for (int i = 0; i < n; ++i) {
      unordered_set<int> uset;
      int sum = 0;
      for (int j = i; j < n; ++j) {
        int x = nums[j];
        uset.insert(x);
        sum += x;
        if (uset.count(sum))
          res++;
      }
    }

    return res;
  }
};