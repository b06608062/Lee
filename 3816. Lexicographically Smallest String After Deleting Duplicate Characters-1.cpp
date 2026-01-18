class Solution {
public:
  string lexSmallestAfterDeletion(string s) {
    unordered_map<char, int> umap;
    for (char ch : s)
      umap[ch]++;
    string res = "";
    for (char ch : s) {
      while (!res.empty() && res.back() > ch && umap[res.back()] > 1) {
        umap[res.back()]--;
        res.pop_back();
      }
      res.push_back(ch);
    }

    while (!res.empty() && umap[res.back()] > 1) {
      umap[res.back()]--;
      res.pop_back();
    }

    return res;
  }
};