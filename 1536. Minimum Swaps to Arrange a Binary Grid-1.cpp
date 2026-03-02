// mark
// 1881
// 計數 + Greedy Bubble Sort + 模擬交換

class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = n - 1; j >= 0; --j)
        if (grid[i][j] == 0)
          cnt++;
        else
          break;
      arr[i] = cnt;
    }

    // cnt >= n - 1 - i
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
      int j = i;
      for (; j < n; ++j)
        if (arr[j] >= n - 1 - i)
          break;
      if (j == n)
        return -1;
      res += j - i;
      int temp = arr[j];
      for (int k = j; k > i; --k)
        arr[k] = arr[k - 1];
      arr[i] = temp;
    }

    return res;
  }
};