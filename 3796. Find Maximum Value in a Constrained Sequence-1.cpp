// mark
// ???
// Two-pass DP / Two-pass relaxation
class Solution {
public:
  int findMaxVal(int n, vector<vector<int>> &restrictions, vector<int> &diff) {
    const int INT = INT_MAX / 2;
    vector<int> arr(n, INT);

    arr[0] = 0;
    for (auto &r : restrictions)
      arr[r[0]] = r[1];

    for (int i = 1; i < n; ++i)
      arr[i] = min(arr[i], arr[i - 1] + diff[i - 1]);

    for (int i = n - 2; i >= 0; --i)
      arr[i] = min(arr[i], arr[i + 1] + diff[i]);

    return *max_element(arr.begin(), arr.end());
  }
};