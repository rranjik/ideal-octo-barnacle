# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor1(self,root,p,q):
        if root is None:
            return None, False
        print(root.val)
        if(root.val == p.val or root.val == q.val):
            return root, False
        p1,c = self.lowestCommonAncestor1(root.left,p,q)
        q1=None
        if(c is False):
            q1,c1 = self.lowestCommonAncestor1(root.right,p,q)
        if(p1 and q1):
            return root, True
        return (p1,False) if p1 else (q1, False)
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.lowestCommonAncestor1(root,p,q)[0]
