// Without RMQ

class Solution {
public:
  set<pair<int, int>> vis;
  long long maxTotalValue(vector<int> &nums, int k) {
    vector<int> ids(nums.size());
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
      return nums[i] == nums[j] ? i < j : nums[i] < nums[j];
    });

    auto computeVal = [&](int i, int j, int l, int r) -> array<long long, 5> {
      if (!vis.insert({i, j}).second)
        return {};
      while (ids[l] <= i || ids[l] >= j)
        ++l;
      while (ids[r] <= i || ids[r] >= j)
        --r;
      return {nums[ids[r]] - nums[ids[l]], i, j, l, r};
    };

    priority_queue<array<long long, 5>> pq;

    pq.push(computeVal(-1, nums.size(), 0, nums.size() - 1));
    long long res = 0;
    while (!pq.empty() && pq.top()[0] && k > 0) {
      auto [val, i, j, l, r] = pq.top();
      pq.pop();
      long long ni = min(ids[l], ids[r]), nj = max(ids[l], ids[r]);
      long long cnt = min((ni - i) * (j - nj), (long long)k);
      k -= cnt;
      res += val * cnt;
      pq.push(computeVal(ni, j, l, r));
      pq.push(computeVal(i, nj, l, r));
    }

    return res;
  }
};