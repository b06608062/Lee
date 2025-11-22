class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord))
      return 0;

    unordered_set<string> vis;
    queue<string> q;
    vis.insert(beginWord);
    q.push(beginWord);

    int cnt = 0;
    while (!q.empty()) {
      cnt++;
      int sz = q.size();
      while (sz--) {
        string cur = q.front();
        if (cur == endWord)
          return cnt;
        q.pop();
        for (int i = 0; i < cur.size(); ++i)
          for (int j = 0; j < 26; ++j) {
            string nxt = cur;
            nxt[i] = char(j + 'a');
            if (!words.count(nxt) || vis.count(nxt))
              continue;
            vis.insert(nxt);
            q.push(nxt);
          }
      }
    }

    return 0;
  }
};