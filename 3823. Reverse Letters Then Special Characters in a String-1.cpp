class Solution {
public:
  string reverseByType(string s) {
    string s1, s2;
    for (auto &ch : s) {
      if (ch >= 'a' && ch <= 'z') {
        s1 += ch;
      } else {
        s2 += ch;
      }
    }

    int n1 = s1.size(), n2 = s2.size();
    for (auto &ch : s) {
      if (ch >= 'a' && ch <= 'z') {
        ch = s1[--n1];
      } else {
        ch = s2[--n2];
      }
    }

    return s;
  }
};