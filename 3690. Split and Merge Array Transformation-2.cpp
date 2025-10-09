template <class T> struct VecHash {
  size_t operator()(const vector<T> &v) const noexcept {
    size_t h = v.size();
    for (auto &x : v) {
      size_t hx = hash<T>{}(x);
      h ^= hx + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
    }
    return h;
  }
};

class Solution {
public:
  int minSplitMerge(vector<int> &nums1, vector<int> &nums2) {
    if (nums1 == nums2)
      return 0;
    int n = nums1.size();

    unordered_set<vector<int>, VecHash<int>> uset{nums1};
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
              if (!uset.count(nxt)) {
                uset.insert(nxt);
                q.push(nxt);
              }
            }
          }
        }
      }
    }

    return -1;
  }
};