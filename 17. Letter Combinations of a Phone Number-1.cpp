class Solution {
public:
  vector<string> res;
  unordered_map<char, string> umap;
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
      return {};

    umap = unordered_map<char, string>({{'2', "abc"},
                                        {'3', "def"},
                                        {'4', "ghi"},
                                        {'5', "jkl"},
                                        {'6', "mno"},
                                        {'7', "pqrs"},
                                        {'8', "tuv"},
                                        {'9', "wxyz"}});

    string s = "";
    helper(digits, s, 0);

    return res;
  }

  void helper(string &digits, string &cur, int i) {
    if (i == digits.size()) {
      res.push_back(cur);
      return;
    }

    for (auto ch : umap[digits[i]]) {
      cur.push_back(ch);
      helper(digits, cur, i + 1);
      cur.pop_back();
    }
  }
};