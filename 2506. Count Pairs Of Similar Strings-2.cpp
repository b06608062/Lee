class Solution {
public:
  int similarPairs(vector<string> &words) {
    unordered_map<int, int> umap;

    int res = 0;
    for (auto &word : words) {
      int mask = 0;
      for (char ch : word)
        mask |= 1 << (ch - 'a');
      res += umap[mask];
      umap[mask]++;
    }

    return res;
  }
};
