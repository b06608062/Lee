class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    unordered_set<int> umap(banned.begin(), banned.end());

    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (i > maxSum)
        break;
      else if (!umap.count(i)) {
        maxSum -= i;
        res++;
      }
    }

    return res;
  }
};