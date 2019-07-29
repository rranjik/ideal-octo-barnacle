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
    boolean isValid(TreeNode root, long min, long max){
        if(root==null){
            return true;
        }
        else{
            System.out.println("root is: "+root.val+"; min: "+min+"; max: "+max);
            if(root.left!=null&&root.right!=null){
                return (root.val>min 
                        && root.val<max 
                        && root.left.val<root.val 
                        && root.right.val>root.val 
                        && isValid(root.left, min, root.val) 
                        && isValid(root.right, root.val, max));
            }
            else if(root.left==null&&root.right!=null){
                return (root.val>min 
                        && root.val<max 
                        && root.right.val>root.val 
                        && isValid(root.right, root.val, max));
            }
            else if(root.right==null&&root.left!=null){
                return (root.val>min 
                        && root.val<max 
                        && root.left.val<root.val 
                        && isValid(root.left, min, root.val));
            }
            else return root.val>min && root.val<max;
        }
    }  
    public boolean isValidBST(TreeNode root) {
        return isValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
