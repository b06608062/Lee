// mark
// 2063
// 字符串哈希入門 + 滑動窗口
// O(n)
class Solution {
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    int n = s.size();

    long long pk = 1;
    for (int i = 0; i < k - 1; ++i)
      pk = pk * power % modulo;

    long long hash = 0;
    int pos = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (i + k < n) {
        hash = (hash - (s[i + k] - 'a' + 1) * pk) % modulo;
        if (hash < 0)
          hash += modulo;
      }
      hash *= power;
      hash += (s[i] - 'a' + 1);
      hash %= modulo;
      if (i + k <= n && hash == hashValue)
        pos = i;
    }

    return s.substr(pos, k);
  }
};