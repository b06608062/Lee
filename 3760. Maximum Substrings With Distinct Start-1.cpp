class Solution {
public:
  int maxDistinct(string s) {
    unordered_set<char> uset;
    for (auto ch : s)
      uset.insert(ch);

    return uset.size();
  }
};