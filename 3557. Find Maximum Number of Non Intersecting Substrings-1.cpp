class Solution {
public:
  int maxSubstrings(string word) {
    int n = word.size();

    unordered_map<char, int> umap; // char, idx

    int b = -1, res = 0;
    for (int i = 0; i < n; ++i) {
      char ch = word[i];
      if (umap.count(ch) && umap[ch] > b) {
        if (i - umap[ch] + 1 >= 4) {
          res++;
          b = i;
        }
      } else {
        umap[ch] = i;
      }
    }

    return res;
  }
};