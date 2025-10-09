class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;

    vector<int> res;
    TreeNode *cur = root;
    while (cur || !st.empty()) {
      if (cur) {
        res.push_back(cur->val);
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top();
        st.pop();
        cur = cur->right;
      }
    }

    return res;
  }
};
