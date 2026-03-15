class Solution {
public:
  int minCost(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    unordered_set<int> uset;
    unordered_map<int, int> cnt1, cnt2;
    for (int i = 0; i < n; ++i) {
      int x1 = nums1[i];
      cnt1[x1]++;
      uset.insert(x1);
      int x2 = nums2[i];
      cnt2[x2]++;
      uset.insert(x2);
    }
    int res = 0;
    for (auto x : uset) {
      int c1 = cnt1[x], c2 = cnt2[x];
      if ((c1 + c2) % 2 != 0)
        return -1;
      res += abs((c1 - c2) / 2);
    }
    return res / 2;
  }
};