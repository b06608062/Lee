class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // 1. 快速檢查：如果目標詞不在字典中，直接返回 0
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
      return 0;

    int M = beginWord.size();

    // 2. 預處理：建立 pattern -> words 的映射 (鄰接表)
    // 例如: "hot" -> {"*ot": ["hot"], "h*t": ["hot"], "ho*": ["hot"]}
    unordered_map<string, vector<string>> adj;
    for (const string &word : wordList) {
      for (int i = 0; i < M; ++i) {
        string pattern = word;
        pattern[i] = '*';
        adj[pattern].push_back(word);
      }
    }

    // 3. 標準 BFS
    queue<pair<string, int>> q;
    q.push({beginWord, 1}); // 存放 {當前單詞, 當前步數}

    unordered_set<string> vis;
    vis.insert(beginWord);

    while (!q.empty()) {
      auto [cur, dist] = q.front();
      q.pop();

      // 抵達目標，返回步數
      if (cur == endWord)
        return dist;

      // 嘗試目前單詞的所有可能模式
      for (int i = 0; i < M; ++i) {
        string pattern = cur;
        pattern[i] = '*';

        // 如果這個模式在鄰接表中存在
        if (adj.count(pattern)) {
          for (string &nxt : adj[pattern]) {
            if (vis.find(nxt) == vis.end()) {
              vis.insert(nxt);
              q.push({nxt, dist + 1});
            }
          }
          // 重點優化：一旦該模式下的所有單詞都處理過，就將其刪除
          // 確保每條「邊」在整個搜尋過程中只會被走訪一次，防止 O(N^2)
          adj.erase(pattern);
        }
      }
    }

    return 0;
  }
};