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
    public int dfs(TreeNode root){
        if(root==null)
            return 0;
        else{
            return dfs(root.left)+dfs(root.right)+1;
        }
    }
    public int countNodes(TreeNode root) {
        return dfs(root);
    }
}
