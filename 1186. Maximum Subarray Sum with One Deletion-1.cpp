class Solution {
public:
  int maximumSum(vector<int> &arr) {
    int n = arr.size();

    vector<int> left(n), right(n);

    int cur = INT_MIN / 2, res = INT_MIN / 2;
    for (int i = 0; i < n; ++i) {
      int x = arr[i];
      cur = max(cur + x, x);
      left[i] = cur;
      res = max(res, cur);
    }

    cur = INT_MIN / 2;
    for (int i = n - 1; i >= 0; --i) {
      int x = arr[i];
      cur = max(cur + x, x);
      right[i] = cur;
    }

    for (int i = 1; i < n - 1; ++i)
      res = max(res, left[i - 1] + right[i + 1]);

    return res;
  }
};