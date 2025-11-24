class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    int maxN = *max_element(nums.begin(), nums.end());

    vector<int> pos;

    long long res = 0;
    for (int r = 0; r < n; ++r) {
      if (nums[r] == maxN)
        pos.push_back(r);

      if (pos.size() >= k) {
        int idx = pos[pos.size() - k];
        res += idx + 1;
      }
    }

    return res;
  }
};
