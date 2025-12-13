// mark
// 1312
// 字串轉指定優先級 + 雙重條件排序
class Solution {
public:
  vector<string> validateCoupons(vector<string> &code,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    int n = code.size();
    unordered_map<string, int> umap({{"electronics", 0},
                                     {"grocery", 1},
                                     {"pharmacy", 2},
                                     {"restaurant", 3}});

    vector<pair<int, string>> items;
    for (int i = 0; i < n; ++i) {
      if (!isActive[i])
        continue;
      if (!umap.count(businessLine[i]))
        continue;
      string &s = code[i];
      if (s.empty())
        continue;
      bool valid = true;
      for (auto ch : s)
        if (!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z') &&
            !(ch >= '0' && ch <= '9') && !(ch == '_')) {
          valid = false;
          break;
        }
      if (!valid)
        continue;

      items.push_back({umap[businessLine[i]], s});
    }

    sort(items.begin(), items.end(), [](auto &a, auto &b) {
      if (a.first != b.first)
        return a.first < b.first;
      return a.second < b.second;
    });

    vector<string> res;
    for (auto &item : items)
      res.push_back(item.second);
    return res;
  }
};