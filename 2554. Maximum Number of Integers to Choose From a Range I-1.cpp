class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    unordered_set<int> umap(banned.begin(), banned.end());

    int i = 1, cnt = 0, sum = 0;
    while (i <= n && sum <= maxSum) {
      if (!umap.count(i)) {
        cnt++;
        sum += i;
      }
      i++;
    }

    return sum > maxSum ? cnt - 1 : cnt;
  }
};