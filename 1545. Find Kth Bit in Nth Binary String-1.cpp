class Solution {
public:
  char findKthBit(int n, int k) {
    string s = "0";
    string s_i_rev = "1";
    while (--n) {
      string nxt_s = s + "1" + s_i_rev;
      s = nxt_s;
      s_i_rev = nxt_s;
      for (auto &ch : s_i_rev)
        if (ch == '0')
          ch = '1';
        else
          ch = '0';
      reverse(s_i_rev.begin(), s_i_rev.end());
    }
    return s[k - 1];
  }
};