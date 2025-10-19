class Solution {
public:
  int missingMultiple(vector<int> &nums, int k) {
    unordered_set<int> uset;
    for (auto x : nums)
      if (x % k == 0)
        uset.insert(x);

    int i = 1;
    while (true) {
      if (!uset.count(i * k))
        return i * k;
      i++;
    }

    return -1;
  }
};