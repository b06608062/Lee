class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    vector<int> arr(value, 0);
    for (auto x : nums)
      arr[(x % value + value) % value]++;

    int res = 0;
    while (arr[res % value]--)
      res++;

    return res;
  }
};