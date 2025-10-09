class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int major = 0, count = 0;
    for (auto x : nums) {
      if (x == major)
        count++;
      else if (--count < 0) {
        major = x;
        count = 1;
      }
    }

    return major;
  }
};