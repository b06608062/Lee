// Follow up: If the BST is modified often (i.e., we can do insert and delete
// operations) and you need to find the kth smallest frequently, how would you
// optimize?
struct SizeNode {
  int val, sz;
  SizeNode *left, *right;
  SizeNode(int x) : val(x), sz(1), left(NULL), right(NULL) {}
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    SizeNode *newRoot = build(root);
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto x : arr)
      newRoot = insert(newRoot, x);
    for (auto x : arr)
      newRoot = erase(newRoot, x);
    SizeNode *cur = newRoot;
    while (cur) {
      int lsz = getSize(cur->left);
      if (k <= lsz)
        cur = cur->left;
      else if (k == lsz + 1)
        return cur->val;
      else {
        k -= lsz + 1;
        cur = cur->right;
      }
    }

    return -1;
  }

  SizeNode *build(TreeNode *root) {
    if (!root)
      return nullptr;
    SizeNode *newNode = new SizeNode(root->val);
    newNode->left = build(root->left);
    newNode->right = build(root->right);
    pull(newNode);
    return newNode;
  }

  SizeNode *insert(SizeNode *root, int val) {
    if (!root)
      return new SizeNode(val);

    if (val < root->val)
      root->left = insert(root->left, val);
    else
      root->right = insert(root->right, val);

    pull(root);
    return root;
  }

  SizeNode *erase(SizeNode *root, int val) {
    if (!root)
      return nullptr;

    if (val < root->val) {
      root->left = erase(root->left, val);
    } else if (val > root->val) {
      root->right = erase(root->right, val);
    } else {
      if (!root->left || !root->right) {
        SizeNode *tmp = root->left ? root->left : root->right;
        delete root;
        return tmp;
      } else {
        SizeNode *cur = root->right;
        while (cur->left)
          cur = cur->left;
        root->val = cur->val;
        root->right = erase(root->right, cur->val);
      }
    }

    pull(root);
    return root;
  }

  int getSize(SizeNode *node) { return node ? node->sz : 0; }

  void pull(SizeNode *node) {
    if (!node)
      return;
    node->sz = 1 + getSize(node->left) + getSize(node->right);
  }
};