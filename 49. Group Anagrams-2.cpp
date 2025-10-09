class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> umap;

    for (string &s : strs) {
      int count[26] = {0};
      for (char c : s)
        count[c - 'a']++;

      string key;
      for (int i = 0; i < 26; ++i)
        if (count[i] > 0)
          key += string(count[i], i + 'a');

      umap[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &[k, v] : umap)
      res.push_back(v);

    return res;
  }
};
