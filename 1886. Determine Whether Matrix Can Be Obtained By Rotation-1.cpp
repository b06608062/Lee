class Solution {
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    if (mat == target)
      return true;
    int n = mat.size();
    for (int round = 0; round < 3; ++round) {
      int l = 0, r = n - 1;
      while (l < r) {
        for (int k = 0; k < r - l; ++k) {
          int temp = mat[l][l + k];
          mat[l][l + k] = mat[r - k][l];
          mat[r - k][l] = mat[r][r - k];
          mat[r][r - k] = mat[l + k][r];
          mat[l + k][r] = temp;
        }
        l++, r--;
      }
      if (mat == target)
        return true;
    }
    return false;
  }
};