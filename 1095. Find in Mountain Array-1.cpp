class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int l = 1, r = n;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (mountainArr.get(m - 1) < mountainArr.get(m))
        l = m + 1;
      else
        r = m;
    }
    int peak = l;
    l = 0, r = peak;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int x = mountainArr.get(m);
      if (x == target)
        return m;
      else if (x < target)
        l = m + 1;
      else
        r = m - 1;
    }

    l = peak, r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int x = mountainArr.get(m);
      if (x == target)
        return m;
      else if (x > target)
        l = m + 1;
      else
        r = m - 1;
    }

    return -1;
  }
};