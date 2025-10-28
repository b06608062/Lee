class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int k = nums.size();

    unordered_map<int, vector<int>> umap;
    set<int> sset;
    for (int i = 0; i < k; ++i) {
      auto &v = nums[i];
      for (auto x : v) {
        umap[x].push_back(i);
        sset.insert(x);
      }
    }

    vector<int> arr(sset.begin(), sset.end());
    int n = arr.size();

    int cnt[3500] = {0};
    int left = 0, right = 0, cur = 0, minL = INT_MAX;
    int start, end;
    while (right < n) {
      int rX = arr[right];
      auto &vR = umap[rX];
      for (auto r : vR)
        if (++cnt[r] == 1)
          cur++;
      if (cur < k) {
        right++;
        continue;
      }
      do {
        int lX = arr[left];
        if (rX - lX + 1 < minL) {
          start = lX, end = rX;
          minL = rX - lX + 1;
        }
        auto &vL = umap[lX];
        for (auto l : vL)
          if (--cnt[l] == 0)
            cur--;
        left++;
      } while (left <= right && cur == k);
      right++;
    }

    return {start, end};
  }
};