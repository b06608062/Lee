class Solution {
public:
  bool doesValidArrayExist(vector<int> &derived) {
    int n = derived.size();
    for (int i = 0; i < 2; i++) {
      int now = i;
      for (int j = 0; j + 1 < n; j++)
        now = now ^ derived[j];
      if ((now ^ i) == derived.back())
        return true;
    }
    return false;
  }
};