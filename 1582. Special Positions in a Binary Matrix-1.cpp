class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> cnt_r(m, 0), cnt_c(n, 0);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j]) {
          cnt_r[i]++;
          cnt_c[j]++;
        }
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] && cnt_r[i] == 1 && cnt_c[j] == 1)
          res++;
    return res;
  }
};