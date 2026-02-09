class Solution {
public:
  int countBeautifulPairs(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        string s1 = to_string(nums[i]);
        string s2 = to_string(nums[j]);
        int x = s1[0] - '0';
        int y = s2[s2.size() - 1] - '0';
        if (gcd(x, y) == 1) {
          res++;
        }
      }
    }

    return res;
  }
};