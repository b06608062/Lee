class Solution {
public:
  long long minOperations(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();

    long long res = 0, n2 = nums2[n], add = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int x = nums1[i], y = nums2[i];
      if (x > y)
        swap(x, y);
      if (x <= n2 && n2 <= y)
        add = 0;
      else
        add = min(add, min(abs(n2 - x), abs(n2 - y)));
      res += y - x;
    }

    return res + 1 + add;
  }
};