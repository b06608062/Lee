class Solution {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int n = arr.size();

    int res = 0;
    for (int k = 2; k < n; ++k)
      for (int j = 1; j < k; ++j) {
        if (abs(arr[j] - arr[k]) > b)
          continue;
        for (int i = 0; i < j; ++i)
          if (abs(arr[i] - arr[j]) <= a && abs(arr[i] - arr[k]) <= c)
            res++;
      }

    return res;
  }
};