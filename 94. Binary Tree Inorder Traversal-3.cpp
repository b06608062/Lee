class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {

    // 儲存 inorder traversal 結果
    vector<int> res;

    // cur = 目前 traversal 所在節點
    TreeNode *cur = root;

    // Morris traversal 主迴圈
    // 條件：只要還有節點要處理
    while (cur) {

      // Case 1:
      // 如果左子樹為空
      //
      // inorder 順序：
      // Left -> Node -> Right
      //
      // 因為沒有 Left，可以直接 visit Node
      if (!cur->left) {

        // visit current node
        res.push_back(cur->val);

        // 移動到右子樹
        cur = cur->right;
      }

      else {

        // Case 2:
        // 如果左子樹存在
        //
        // 我們必須先完成左子樹 traversal，
        // 再回來 visit current node
        //
        // 但我們不能用 stack / recursion
        //
        // 解法：
        // 找 inorder predecessor

        // predecessor = 左子樹最右邊的節點
        //
        // 性質：
        // inorder traversal 中，
        // predecessor 就是 current 前一個節點
        TreeNode *pre = cur->left;

        // 找最右節點
        //
        // 條件：
        // pre->right == nullptr
        //    或
        // pre->right == cur (代表 thread 已存在)
        while (pre->right && pre->right != cur) {

          pre = pre->right;
        }

        // Case 2.1:
        // 第一次到 current
        //
        // pre->right == nullptr
        //
        // 代表：
        // 左子樹還沒 traversal 完
        if (!pre->right) {

          // 建立 thread
          //
          // 目的：
          // traversal 完左子樹後
          // 可以回到 current
          //
          // 相當於 recursion stack 的 return address
          pre->right = cur;

          // 繼續 traversal 左子樹
          cur = cur->left;
        }

        // Case 2.2:
        // 第二次回到 current
        //
        // pre->right == cur
        //
        // 代表：
        // 左子樹已 traversal 完
        else {

          // 拆除 thread
          //
          // 恢復 tree 原始結構
          pre->right = nullptr;

          // visit current node
          res.push_back(cur->val);

          // traversal 右子樹
          cur = cur->right;
        }
      }
    }

    return res;
  }
};