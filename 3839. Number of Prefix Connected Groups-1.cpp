class Solution {
public:
  int prefixConnected(vector<string> &words, int k) {
    unordered_map<string, int> umap;
    for (auto &w : words)
      if (w.size() >= k)
        umap[w.substr(0, k)]++;

    int res = 0;
    for (auto &[k, v] : umap)
      if (v >= 2)
        res++;
    return res;
  }
};