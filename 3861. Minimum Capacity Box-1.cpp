class Solution {
public:
  int minimumIndex(vector<int> &capacity, int itemSize) {
    int n = capacity.size();
    int cur = INT_MAX / 2, idx = -1;
    for (int i = 0; i < n; ++i) {
      int x = capacity[i];
      if (x >= itemSize && x < cur) {
        cur = x;
        idx = i;
      }
    }
    return idx;
  }
};