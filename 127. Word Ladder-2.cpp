class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
      return 0;

    unordered_set<string> beginSet{beginWord}, endSet{endWord},
        vis{beginWord, endWord};

    int len = 1;
    while (!beginSet.empty() && !endSet.empty()) {
      if (beginSet.size() > endSet.size())
        swap(beginSet, endSet);
      len++;
      unordered_set<string> temp;
      for (auto &word : beginSet) {
        string cur = word;
        for (int i = 0; i < cur.size(); i++) {
          char old = cur[i];
          for (char c = 'a'; c <= 'z'; c++) {
            cur[i] = c;
            if (endSet.count(cur))
              return len;
            if (dict.count(cur) && !vis.count(cur)) {
              vis.insert(cur);
              temp.insert(cur);
            }
          }
          cur[i] = old;
        }
      }
      beginSet = temp;
    }
    return 0;
  }
};
