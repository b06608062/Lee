// mark
// 2477
// BFS + 奇偶性 + Set 優化區間搜尋

class Solution {
public:
  int minOperations(string s, int k) {
    // n 是字串長度，m 用來統計初始狀態下 '0' 的個數
    int n = s.size(), m = 0;

    // dist[i] 紀錄變成「剛好有 i 個 0」所需的最少操作次數
    // 初始設為無限大 (INT_MAX) 表示尚未到達
    vector<int> dist(n + 1, INT_MAX);

    // nodeSets[0] 存放偶數狀態，nodeSets[1] 存放奇數狀態
    // 用 set 是為了能在 BFS 過程中快速找到範圍內的「未訪問」狀態並刪除
    vector<set<int>> nodeSets(2);

    for (int i = 0; i <= n; i++) {
      nodeSets[i % 2].insert(
          i); // 初始化：將所有可能的 0 數量放入對應的奇偶集合
      if (i < n && s[i] == '0') {
        m++; // 計算初始字串中有幾個 '0'
      }
    }

    queue<int> q;
    q.push(m);                // 起點：目前有 m 個 '0'
    dist[m] = 0;              // 起點步數為 0
    nodeSets[m % 2].erase(m); // 從集合移除，代表已訪問 (避免重複計算)

    while (!q.empty()) {
      m = q.front();
      q.pop();

      // --- 核心數學邏輯：計算翻轉後的變化範圍 ---
      // 假設翻轉了 c 個 '0'，則這 c 個 '0' 變 '1'，另外 (k-c) 個 '1' 變 '0'
      // 新的 '0' 數量 = m - c + (k - c) = m + k - 2c

      // c1: 最少必須翻轉多少個 '0' (當 '1' 不夠多時被迫翻轉 '0')
      int c1 = max(k - (n - m), 0);
      // c2: 最多能翻轉多少個 '0' (現有的 '0' 數量與 k 的較小值)
      int c2 = min(m, k);

      // 根據 m + k - 2c 公式，得到新狀態的最小值 (lnode) 與最大值 (rnode)
      int lnode = m + k - 2 * c2;
      int rnode = m + k - 2 * c1;

      // 根據奇偶性選擇對應的集合
      auto &nodeSet = nodeSets[lnode % 2];

      // --- 區間搜尋優化 ---
      // 在 set 中尋找落在 [lnode, rnode] 範圍內且尚未被訪問的數字
      for (auto iter = nodeSet.lower_bound(lnode);
           iter != nodeSet.end() && *iter <= rnode;) {

        int m2 = *iter; // 找到新的狀態 m2
        dist[m2] = dist[m] + 1;
        q.push(m2); // 加入隊列繼續搜尋

        iter = next(iter); // 先移動迭代器
        nodeSet.erase(
            m2); // 刪除該點，確保每個狀態只會進出 Queue 一次 (O(N log N))
      }
    }

    // 如果 dist[0] 仍為無限大，表示無法達成全部為 '1' (0 個 '0')
    return dist[0] == INT_MAX ? -1 : dist[0];
  }
};