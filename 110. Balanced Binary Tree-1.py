# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def f(root):
            if root is None:
                return 0
            left = f(root.left)
            if left < 0:
                return -1
            right = f(root.right)
            if right < 0 or abs(left - right) > 1:
                return -1
            return max(left, right) + 1

        return f(root) != -1
