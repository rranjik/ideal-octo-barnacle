/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int mD(TreeNode root, int pd){
        if(root==null){
            return pd;
        }
        else{
            return Math.max(mD(root.left, pd+1), mD(root.right, pd+1));
        }
    }
    public int maxDepth(TreeNode root) {
        return mD(root, 0);
    }
}
