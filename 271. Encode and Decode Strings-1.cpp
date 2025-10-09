class Solution {
public:
  // Encode: Store string length + '#' + string
  string encode(vector<string> &strs) {
    string en = "";
    for (auto &s : strs)
      en += to_string(s.size()) + "#" + s;

    return en;
  }

  vector<string> decode(string s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
      int j = s.find('#', i);
      int len = stoi(s.substr(i, j - i));
      res.push_back(s.substr(j + 1, len));
      i = j + 1 + len;
    }

    return res;
  }
};