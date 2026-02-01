class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int diff = 26;
    for (auto &ch : letters) {
      if (ch > target) {
        diff = min(diff, ch - target);
      }
    }

    return diff == 26 ? letters[0] : target + diff;
  }
};