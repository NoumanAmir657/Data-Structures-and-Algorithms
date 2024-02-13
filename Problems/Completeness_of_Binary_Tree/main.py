# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        q = [root]
        nullEncountered = False
        lastLevel = False
        while q:
            tmp = len(q)
            nullEncountered = False
            for i in range(tmp):
                current = q.pop(0)
                if current.left:
                    if nullEncountered:
                        return False
                    if lastLevel:
                        return False
                    q.append(current.left)
                else:
                    nullEncountered = True
                
                if current.right:
                    if nullEncountered:
                        return False
                    if lastLevel:
                        return False
                    q.append(current.right)
                else:
                    nullEncountered = True
            
            if nullEncountered:
                lastLevel = True
        
        return True
