/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> arr;
  TreeNode *sortedListToBST(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
      arr.push_back(cur->val);
      cur = cur->next;
    }

    return helper(0, arr.size() - 1);
  }

  TreeNode *helper(int l, int r) {
    if (l > r)
      return nullptr;
    if (l == r)
      return new TreeNode(arr[l]);
    int m = (l + r + 1) / 2;
    TreeNode *root = new TreeNode(arr[m]);
    root->left = helper(l, m - 1);
    root->right = helper(m + 1, r);
    return root;
  }
};