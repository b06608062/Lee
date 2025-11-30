class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();

    unordered_map<char, int> umap;
    for (int i = 0; i < n; ++i)
      umap[s[i]] = i;

    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
      end = max(end, umap[s[i]]);
      if (i == end) {
        res.push_back(end - start + 1);
        start = i + 1;
        end = i + 1;
      }
    }

    return res;
  }
};

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i)
      umap[s[i]] = i;

    vector<int> res;
    int start = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
      if (i > cur) {
        res.push_back(i - start);
        cur = i;
        start = i;
      }
      cur = max(cur, umap[s[i]]);
    }

    res.push_back(n - start);
    return res;
  }
};