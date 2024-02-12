# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        p1 = []
        c1 = root
        while c1 != p:
            p1.append(c1)
            if p.val < c1.val:
                c1 = c1.left
            elif p.val > c1.val:
                c1 = c1.right
        p1.append(c1)
        
        p2 = []
        c2 = root
        while c2 != q:
            p2.append(c2)
            if q.val < c2.val:
                c2 = c2.left
            elif q.val > c2.val:
                c2 = c2.right
        p2.append(c2) 

        i = 0
        while True:
            if i < len(p1) and i < len(p2):
                if p1[i].val == p2[i].val:
                    i += 1
                    continue
                else:
                    break
            else:
                break
        
        return p1[i-1]


