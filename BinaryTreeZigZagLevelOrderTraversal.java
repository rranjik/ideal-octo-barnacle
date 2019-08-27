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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> level = new ArrayList<>();
        if(root!=null){
            s1.push(root);
            while(!s1.empty()||!s2.empty()){
                while(!s1.empty()){
                    TreeNode node = s1.peek();
                    s1.pop();
                    System.out.println(node.val);
                    level.add(node.val);
                    if(node.left!=null) s2.push(node.left);
                    if(node.right!=null) s2.push(node.right);
                }
                if(level.size()>0) {
                    List<Integer> nl = new ArrayList<>(level);
                    res.add(nl);
                    System.out.println("Size of res is: " + res.size());
                }
                level.clear();
                while(!s2.empty()){
                    TreeNode node = s2.peek();
                    s2.pop();
                    System.out.println(node.val);
                    level.add(node.val);
                    if(node.right!=null) s1.push(node.right);
                    if(node.left!=null) s1.push(node.left);
                }
                if(level.size()>0) {
                    List<Integer> nl = new ArrayList<>(level);
                    res.add(nl);
                    System.out.println("Size of res is: " + res.size());
                }
                level.clear();
            }
        }
        return res;
    }
}
