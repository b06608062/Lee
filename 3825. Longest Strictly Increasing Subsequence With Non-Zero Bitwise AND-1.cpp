// mark
// ???
// Bitwise AND > 0 的充要條件為：該子序列中所有元素在至少一個 bit pos 都為 1
// 枚舉每個 bit pos，找最長 LIS (Patience Sorting O(n log n))
// 由左至右掃描：遍歷陣列中的每一個元素
// 對於當前元素 x，必須將其放在第一個「大於等於 x」的堆的最上方
// 如果當前所有堆的頂端元素都小於 x，則在右側新建一個堆，並將 x 放進去
// 每一堆的頂端元素從左到右一定是「嚴格遞增」的
// 透過不斷更新堆頂為更小的值，我們為後續的元素保留了最大的「接龍空間」
// 每個 堆i 的頂端元素 x 意義是，存在一條長度為 i + 1 的 IS，結尾為 x

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i <= 31; ++i) {
      vector<int> arr;
      for (auto x : nums) {
        if (x & (1 << i)) {
          arr.push_back(x);
        }
      }
      if (arr.empty())
        continue;
      vector<int> tail;
      for (auto x : arr) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) {
          tail.push_back(x);
        } else {
          *it = x;
        }
      }
      res = max(res, (int)tail.size());
    }

    return res;
  }
};