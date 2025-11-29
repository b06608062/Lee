/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int l = 1, r = n - 2;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (mountainArr.get(m) < mountainArr.get(m + 1))
        l = m + 1;
      else
        r = m;
    }
    int peak = l;
    int findLeft = helper1(mountainArr, 0, peak, target);
    return findLeft == -1 ? helper2(mountainArr, peak, n - 1, target)
                          : findLeft;
  }

  int helper1(MountainArray &mountainArr, int l, int r, int target) {
    while (l <= r) {
      int m = l + (r - l) / 2;
      int val = mountainArr.get(m);
      if (val == target)
        return m;
      else if (val < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return -1;
  }

  int helper2(MountainArray &mountainArr, int l, int r, int target) {
    while (l <= r) {
      int m = l + (r - l) / 2;
      int val = mountainArr.get(m);
      if (val == target)
        return m;
      else if (val < target)
        r = m - 1;
      else
        l = m + 1;
    }
    return -1;
  }
};