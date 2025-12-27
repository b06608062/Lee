// mark
// 2359
// Offline Query + Bitwise Trie
struct TrieNode {
  int x;
  TrieNode *children[2];
  TrieNode() {
    int x = -1;
    children[0] = children[1] = nullptr;
  }
};

class Solution {
public:
  TrieNode *root;
  void insert(int x) {
    TrieNode *ptr = root;
    for (int i = 31; i >= 0; --i) {
      int bit = x >> i & 1;
      if (!ptr->children[bit])
        ptr->children[bit] = new TrieNode();
      ptr = ptr->children[bit];
    }
    ptr->x = x;
  }

  int find(int x) {
    TrieNode *ptr = root;
    for (int i = 31; i >= 0; --i) {
      int bit = !(x >> i & 1);
      if (ptr->children[bit])
        ptr = ptr->children[bit];
      else
        ptr = ptr->children[!bit];
    }
    return ptr->x;
  }
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);
    sort(queries.begin(), queries.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });

    root = new TrieNode();

    vector<int> res(queries.size());

    int i = 0;
    for (auto &q : queries) {
      int x = q[0], m = q[1], idx = q[2];
      while (i < n && nums[i] <= m) {
        insert(nums[i]);
        i++;
      }
      if (i == 0)
        res[idx] = -1;
      else
        res[idx] = x ^ find(x);
    }

    return res;
  }
};