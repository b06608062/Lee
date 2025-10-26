class Solution {
public:
  long long findScore(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> arr;
    for (int i = 0; i < n; ++i)
      arr.push_back({nums[i], i});

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
      if (a[0] != b[0])
        return a[0] < b[0];
      return a[1] < b[1];
    });

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int x = arr[i][0], idx = arr[i][1];
      if (nums[idx] != -1) {
        res += x;
        if (idx - 1 >= 0)
          nums[idx - 1] = -1;
        if (idx + 1 < n)
          nums[idx + 1] = -1;
      }
    }

    return res;
  }
};