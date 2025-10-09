class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size();

    int case1 = 1, case2 = 1, res = 1;
    for (int i = n - 2; i >= 0; --i) {
      if ((i % 2 == 0 && arr[i] < arr[i + 1]) || (i % 2 && arr[i] > arr[i + 1]))
        case1 = case1 + 1;
      else
        case1 = 1;

      if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 && arr[i] < arr[i + 1]))
        case2 = case2 + 1;
      else
        case2 = 1;

      res = max(res, max(case1, case2));
    }

    return res;
  }
};