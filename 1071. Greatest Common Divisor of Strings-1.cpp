class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1)
      return "";

    return str1.substr(0, gcd(str1.size(), str2.size()));
  }

  // int gcd(int a, int b) {
  //   if (b == 0)
  //     return a;

  //   return gcd(b, a % b);
  // }

  // int gcd(int a, int b) {
  //   if (a < b)
  //     swap(a, b);
  //   while (b) {
  //     int r = a % b;
  //     a = b;
  //     b = r;
  //   }

  //   return a;
  // }
};