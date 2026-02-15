// mark
// 利用 inorder 特性依序處理
class Solution {
public:
  ListNode *ptr;
  TreeNode *sortedListToBST(ListNode *head) {
    ptr = head;
    int n = 0;
    while (ptr) {
      n++;
      ptr = ptr->next;
    }

    ptr = head;
    return helper(0, n - 1);
  }

  TreeNode *helper(int l, int r) {
    if (l > r)
      return nullptr;
    int m = (l + r + 1) / 2;
    auto left = helper(l, m - 1);
    int val = ptr->val;
    ptr = ptr->next;
    auto right = helper(m + 1, r);
    return new TreeNode(val, left, right);
  }
};

// 快慢指針
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)
      return nullptr;
    if (!head->next)
      return new TreeNode(head->val);

    ListNode *slow = head, *fast = head, *pre = nullptr;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    pre->next = nullptr;

    TreeNode *root = new TreeNode(slow->val);

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);

    return root;
  }
};