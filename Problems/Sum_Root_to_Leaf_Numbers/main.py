# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        res = []

        def dfs(root, s):
            nonlocal res
            if root == None:
                return
            
            s += str(root.val)
            if root.left == None and root.right == None:
                res.append(s)
            dfs(root.left, s)
            dfs(root.right, s)
        
        dfs(root, '')
        return sum(int(s) for s in res)
