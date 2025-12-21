// mark
// ???
class Solution {
public:
  int minSwaps(vector<int> &nums, vector<int> &forbidden) {
    int n = nums.size();

    unordered_map<int, int> freex; // cnt for valid nums
    unordered_map<int, int> freey; // cnt for valid forbidden
    unordered_map<int, int> ban;

    int freeCnt = 0, banCnt = 0;
    for (int i = 0; i < n; ++i) {
      int x = nums[i], y = forbidden[i];
      if (x != y) {
        freeCnt++;
        freex[x]++;
        freey[y]++;
      } else {
        banCnt++;
        ban[x]++;
      }
    }

    int x = -1, cntx = 0;
    for (auto [k, v] : ban)
      if (v > cntx) {
        x = k;
        cntx = v;
      }

    if (cntx <= banCnt / 2)
      return (banCnt + 1) / 2;

    int remain = cntx - (banCnt - cntx);
    if (freeCnt - freex[x] - freey[x] >= remain)
      return cntx;

    return -1;
  }
};