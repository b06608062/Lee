class Solution {
public:
  int minSplitMerge(vector<int> &nums1, vector<int> &nums2) {
    if (nums1 == nums2)
      return 0;
    int n = nums1.size();

    set<vector<int>> sset{nums1};
    queue<vector<int>> q;

    q.push(nums1);
    int res = 0;
    while (!q.empty()) {
      res++;
      int size = q.size();
      while (size--) {
        auto cur = q.front();
        q.pop();
        for (int len = 1; len < n; ++len) {
          for (int L = 0; L + len - 1 <= n - 1; ++L) {
            int R = L + len - 1;
            vector<int> split, remain;
            split.reserve(len);
            remain.reserve(n - len);
            for (int i = 0; i < n; ++i)
              if (i < L || i > R)
                remain.push_back(cur[i]);
              else
                split.push_back(cur[i]);
            for (int j = 0; j <= remain.size(); ++j) {
              if (j == L)
                continue;
              auto nxt = remain;
              nxt.insert(nxt.begin() + j, split.begin(), split.end());
              if (nxt == nums2)
                return res;
              if (sset.insert(nxt).second)
                q.push(nxt);
            }
          }
        }
      }
    }

    return -1;
  }
};