class Solution {
public:
  long long minOperations(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();

    int diff[100001] = {0};

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int x1 = nums1[i], x2 = nums2[i];
      if (x1 > x2)
        swap(x1, x2);
      res += x2 - x1;
      diff[x1]++;
      if (x2 + 1 <= 100000)
        diff[x2 + 1]--;
    }

    int seen[100001] = {0};
    int cur = 0;
    for (int i = 1; i <= 100000; ++i) {
      cur += diff[i];
      if (cur)
        seen[i] = 1;
    }

    int last = nums2[n];
    int up = 1e5, down = 100000;
    for (int i = last; i <= 100000; ++i)
      if (seen[i]) {
        up = i - last;
        break;
      }
    for (int i = last; i >= 0; --i)
      if (seen[i]) {
        down = last - i;
        break;
      }

    return res + min(up, down) + 1;
  }
};