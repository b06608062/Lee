class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    int m = languages.size();

    // 用 uset 紀錄每個人會的語言
    vector<unordered_set<int>> p(m + 1);
    for (int j = 1; j <= m; ++j) {
      auto &ls = languages[j - 1];
      for (auto l : ls)
        p[j].insert(l);
    }

    // 預處理
    // 標記每個朋友關係是否能直接溝通
    vector<bool> pass(friendships.size(), false);
    for (int e = 0; e < friendships.size(); ++e) {
      int u = friendships[e][0], v = friendships[e][1];
      for (int j = 1; j <= n; ++j)
        // 只要有一個共同語言就能溝通
        if (p[u].count(j) && p[v].count(j)) {
          pass[e] = true;
          break;
        }
    }

    int res = m;
    for (int i = 1; i <= n; ++i) {
      vector<bool> teach(m, false);
      for (int e = 0; e < friendships.size(); ++e) {
        int u = friendships[e][0], v = friendships[e][1];
        if (!pass[e])
          // 如果無法直接溝通，則彼此都要教這個語言 i
          // 先標記起來
          teach[u] = teach[v] = true;
      }
      int cnt = 0;
      // 計算需要教多少人這個語言 i
      for (int j = 1; j <= m; ++j)
        // 本來就會 i 語言就不需要教
        if (teach[j] && !p[j].count(i))
          cnt++;
      // 更新答案
      res = min(res, cnt);
    }

    return res;
  }
};