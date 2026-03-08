class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    int n = nums.size();
    string res = "";
    for (int i = 0; i < n; ++i) {
      res += (1 - (nums[i][i] - '0')) + '0';
    }
    return res;
  }
};