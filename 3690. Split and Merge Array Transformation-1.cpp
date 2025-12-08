// mark
// 1982
// BSF + 陣列拆分與合併模擬 + Set 去重
class Solution {
public:
  int minSplitMerge(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();

    if (nums1 == nums2)
      return 0;

    set<vector<int>> vis;
    queue<vector<int>> q;

    int step = 0;
    vis.insert(nums1);
    q.push(nums1);
    while (!q.empty()) {
      step++;
      int sz = q.size();
      while (sz--) {
        auto cur = q.front();
        q.pop();
        for (int l = 0; l < n; ++l)
          for (int r = l; r < n; ++r) {
            if (r - l + 1 == n)
              continue;
            vector<int> split;
            vector<int> remain;
            for (int i = 0; i < n; ++i)
              if (i >= l && i <= r)
                split.push_back(cur[i]);
              else
                remain.push_back(cur[i]);
            for (int i = 0; i <= remain.size(); ++i) {
              if (i == l)
                continue;
              auto nxt = remain;
              nxt.insert(nxt.begin() + i, split.begin(), split.end());
              if (nxt == nums2)
                return step;
              if (!vis.count(nxt)) {
                vis.insert(nxt);
                q.push(nxt);
              }
            }
          }
      }
    }

    return -1;
  }
};