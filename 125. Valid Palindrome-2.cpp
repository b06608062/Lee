class Solution {
public:
  bool isPalindrome(string s) {
    string clean_s = "";
    for (auto ch : s)
      if (isalnum(ch))
        clean_s += tolower(ch);

    string t(clean_s.rbegin(), clean_s.rend());
    return t == clean_s;
  }

  bool isalnum(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
  }
  char tolower(char ch) {
    if (ch >= 'A' && ch <= 'Z')
      return ch - 'A' + 'a';
    return ch;
  }
};