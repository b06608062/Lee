class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> umap;

    for (string &s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      umap[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &[k, v] : umap)
      res.push_back(v);

    return res;
  }
};
