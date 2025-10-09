class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();

    int cnt1 = 0, cnt2 = 0, candidate1 = 0, candidate2 = 1;
    for (int x : nums) {
      if (x == candidate1)
        cnt1++;
      else if (x == candidate2)
        cnt2++;
      else if (cnt1 == 0) {
        candidate1 = x;
        cnt1 = 1;
      } else if (cnt2 == 0) {
        candidate2 = x;
        cnt2 = 1;
      } else {
        cnt1--;
        cnt2--;
      }
    }

    cnt1 = cnt2 = 0;
    for (int x : nums)
      if (x == candidate1)
        cnt1++;
      else if (x == candidate2)
        cnt2++;

    vector<int> res;
    if (cnt1 > n / 3)
      res.push_back(candidate1);

    if (cnt2 > n / 3)
      res.push_back(candidate2);

    return res;
  }
};