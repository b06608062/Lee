class Solution {
public:
  ListNode *cur;
  TreeNode *sortedListToBST(ListNode *head) {
    int n = 0;
    cur = head;
    while (cur) {
      n++;
      cur = cur->next;
    }
    cur = head;
    return build(0, n - 1);
  }

  TreeNode *build(int l, int r) {
    if (l > r)
      return nullptr;
    int m = (l + r) / 2;

    TreeNode *left = build(l, m - 1);

    TreeNode *root = new TreeNode(cur->val);
    cur = cur->next;

    TreeNode *right = build(m + 1, r);

    root->left = left;
    root->right = right;
    return root;
  }
};
