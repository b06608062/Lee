// mark
// ???
// 對齊下限 + 推進下限
// 為了讓極差縮小，唯一的辦法就是把目前的最小值變大

class Solution {
public:
  int getMinRange(const vector<int> &nums, int start_parity) {
    int n = nums.size();

    vector<vector<int>> choices(n);

    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> min_heap;

    int current_max = INT_MIN;
    for (int i = 0; i < n; ++i) {
      int target_p = (i % 2 == 0) ? start_parity : 1 - start_parity;
      if (abs(nums[i]) % 2 == target_p)
        choices[i] = {nums[i]};
      else
        choices[i] = {nums[i] - 1, nums[i] + 1};
      min_heap.push({choices[i][0], i});
      current_max = max(current_max, choices[i][0]);
    }

    vector<int> opt_idx(n, 0);
    int min_diff = INT_MAX;
    while (!min_heap.empty()) {
      auto [current_min, i] = min_heap.top();
      min_heap.pop();
      min_diff = min(min_diff, current_max - current_min);
      if (opt_idx[i] + 1 < choices[i].size()) {
        opt_idx[i]++;
        int next_val = choices[i][opt_idx[i]];
        min_heap.push({next_val, i});
        current_max = max(current_max, next_val);
      } else
        break;
    }

    return min_diff;
  }

  vector<int> makeParityAlternating(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1)
      return {0, 0};

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
      int diff = (i % 2) ^ (abs(nums[i]) % 2);
      cnt0 += diff ? 1 : 0;
      cnt1 += diff ? 0 : 1;
    }

    if (cnt0 < cnt1)
      return {cnt0, getMinRange(nums, 0)};
    else if (cnt1 < cnt0)
      return {cnt1, getMinRange(nums, 1)};
    else
      return {cnt0, min(getMinRange(nums, 0), getMinRange(nums, 1))};
  }
};