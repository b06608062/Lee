// mark
// x, y, z
// c = y + z
// 2(x + y) = x + Nc + y
// x + y = Nc
// x + (c - z) = Nc
// x = (N - 1)c + z
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = nums[0], fast = nums[0];
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    int slow2 = nums[0];
    while (slow != slow2) {
      slow = nums[slow];
      slow2 = nums[slow2];
    }

    return slow;
  }
};