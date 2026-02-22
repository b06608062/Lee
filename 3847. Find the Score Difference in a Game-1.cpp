class Solution {
public:
  int scoreDifference(vector<int> &nums) {
    int n = nums.size();

    bool turn = true;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] % 2 == 1)
        turn = turn ? false : true;
      if (i % 6 == 5)
        turn = !turn;
      res += turn ? nums[i] : -nums[i];
    }

    return res;
  }
};