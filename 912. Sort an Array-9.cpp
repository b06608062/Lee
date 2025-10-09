// counting sort

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    constexpr int MINV = -50000;
    constexpr int MAXV = 50000;
    constexpr int RANGE = MAXV - MINV + 1; // 100001
    const int OFFSET = -MINV;              // 50000

    vector<int> cnt(RANGE, 0);
    for (int x : nums)
      ++cnt[x + OFFSET];

    int idx = 0;
    for (int v = 0; v < RANGE; ++v)
      while (cnt[v]--)
        nums[idx++] = v - OFFSET;

    return nums;
  }
};
