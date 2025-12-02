class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    m = image.size(), n = image[0].size();
    if (image[sr][sc] == color)
      return image;

    dfs(image, sr, sc, image[sr][sc], color);
    return image;
  }

  void dfs(vector<vector<int>> &image, int i, int j, int target, int color) {
    if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != target)
      return;
    image[i][j] = color;
    for (int d = 0; d < 4; ++d)
      dfs(image, i + dirs[d], j + dirs[d + 1], target, color);
  }
};