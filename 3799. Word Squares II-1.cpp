class Solution {
public:
  vector<string> subset;
  set<vector<string>> sset;
  vector<vector<string>> wordSquares(vector<string> &words) {
    dfs1(words, 0);
    vector<vector<string>> res(sset.begin(), sset.end());

    return res;
  }

  void dfs1(vector<string> &words, int i) {
    if (subset.size() == 4) {
      dfs2(subset, 0);
      return;
    }
    for (int j = i; j < words.size(); ++j) {
      subset.push_back(words[j]);
      dfs1(words, j + 1);
      subset.pop_back();
    }
  }

  void dfs2(vector<string> &arr, int i) {
    if (i == 4) {
      if (valid(arr))
        sset.insert(arr);
      return;
    }
    for (int j = i; j < 4; ++j) {
      swap(arr[i], arr[j]);
      dfs2(arr, i + 1);
      swap(arr[i], arr[j]);
    }
  }

  bool valid(vector<string> &arr) {
    return arr[0][0] == arr[1][0] && arr[0][3] == arr[2][0] &&
           arr[3][0] == arr[1][3] && arr[3][3] == arr[2][3];
  }
};