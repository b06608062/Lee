class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size();
    int up = 1, down = 1, res = 1;
    for (int i = 1; i < n; ++i) {
      if (arr[i] > arr[i - 1]) {
        up = down + 1;
        down = 1;
      } else if (arr[i] < arr[i - 1]) {
        down = up + 1;
        up = 1;
      } else {
        up = 1;
        down = 1;
      }
      res = max(res, max(up, down));
    }

    return res;
  }
};