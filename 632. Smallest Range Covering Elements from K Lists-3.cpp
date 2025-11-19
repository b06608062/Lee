class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int k = nums.size();

    // 最小堆（min-heap）
    // 元素格式：(值 value, 所屬第幾個 list, 該 list 內的 index)
    // greater<> 代表使用「最小值」在 top 的 min-heap
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;

    // curMax 用來記錄目前 heap 中的最大值
    // 因為 heap 只能取得最小值，我們必須手動追蹤最大值，才能形成區間 [min, max]
    int curMax = INT_MIN;

    // Step 1：把每個 list 的第一個元素放進 min-heap
    for (int i = 0; i < k; ++i) {
      int val = nums[i][0];
      pq.push({val, i, 0});      // (value, listID, indexInList)
      curMax = max(curMax, val); // 更新目前最大值
    }

    // 最佳區間的左右端點（初始為極大區間）
    int bestL = 0, bestR = INT_MAX;

    // Step 2：開始進行「k 條指標同步前進」的核心流程
    while (true) {

      // 取出目前最小值（區間的左端）
      auto [val, row, idx] = pq.top();
      pq.pop();

      // val = 目前所有選中元素中的最小值
      // curMax = 目前所有選中元素中的最大值
      // → 形成區間 [val, curMax]

      // 若這個區間更小（長度更短），就更新答案
      if (curMax - val < bestR - bestL) {
        bestL = val;
        bestR = curMax;
      }

      // 若該 list 已經沒有下一個元素，演算法必須終止
      // 因為我們無法從這個 list 再挑更大的值來維持 k 個來源
      if (idx + 1 == nums[row].size())
        break;

      // 取出該 list 的下一個值
      int nextVal = nums[row][idx + 1];

      // 推入 min-heap
      pq.push({nextVal, row, idx + 1});

      // 更新目前最大值（curMax 必須維持所有元素中的最大者）
      curMax = max(curMax, nextVal);
    }

    // 回傳最終最佳區間
    return {bestL, bestR};
  }
};
