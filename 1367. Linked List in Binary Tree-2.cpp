class Solution {
public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    // 1. 把 linked list 轉成 pattern 陣列
    vector<int> pat;
    for (ListNode *p = head; p != nullptr; p = p->next) {
      pat.push_back(p->val);
    }
    int m = pat.size();
    if (m == 0)
      return true;

    // 2. 建 KMP 的 lps 陣列
    vector<int> lps(m, 0);
    buildLPS(pat, lps);

    // 3. DFS + KMP
    return dfs(root, pat, lps, 0);
  }

private:
  void buildLPS(const vector<int> &pat, vector<int> &lps) {
    int m = pat.size();
    int len = 0; // 當前 prefix 長度
    // i 從 1 開始，因為 lps[0] = 0
    for (int i = 1; i < m; ++i) {
      while (len > 0 && pat[i] != pat[len]) {
        len = lps[len - 1]; // 跳回較短的 prefix
      }
      if (pat[i] == pat[len]) {
        ++len;
      }
      lps[i] = len;
    }
  }

  bool dfs(TreeNode *node, const vector<int> &pat, const vector<int> &lps,
           int k) {
    if (!node)
      return false;

    // k 是到父節點為止的已匹配長度
    // 對當前節點值做 KMP 轉移
    while (k > 0 && node->val != pat[k]) {
      k = lps[k - 1];
    }
    if (node->val == pat[k]) {
      ++k;
    }

    // 若已經匹配到整個 pattern，直接成功
    if (k == (int)pat.size())
      return true;

    // 繼續往左右子樹走，帶著目前匹配前綴長度 k
    return dfs(node->left, pat, lps, k) || dfs(node->right, pat, lps, k);
  }
};
