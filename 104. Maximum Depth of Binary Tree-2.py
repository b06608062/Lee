# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        res = 0

        def f(root, cnt):
            if root is None:
                return
            cnt += 1
            nonlocal res
            res = max(res, cnt)
            f(root.left, cnt)
            f(root.right, cnt)

        f(root, 0)

        return res
