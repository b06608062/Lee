class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string prefix = strs[0];

    for (int i = 1; i < strs.size(); ++i)
      while (strs[i].find(prefix) != 0) { // 回傳第一次出現的索引 or npos
        prefix = prefix.substr(0, prefix.size() - 1);
        if (prefix.empty())
          return "";
      }

    return prefix;
  }
};
