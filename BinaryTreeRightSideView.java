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
    public class NodeAndLevel{
        public TreeNode n;
        public Integer l;
        public NodeAndLevel(TreeNode n, Integer l){
            this.n=n;
            this.l=l;
        }
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        List<List<Integer>> bfs = new ArrayList<>();
        if(root==null)
            return res;
        Queue<NodeAndLevel> q = new LinkedList<>();
        Integer level = 0;
        NodeAndLevel nl = new NodeAndLevel(root, level);
        q.add(nl);
        while(!(q.peek()==null)){
            NodeAndLevel nal = q.remove();
            Integer tl = nal.l;
            TreeNode tn = nal.n;
            if(tl<bfs.size()){
                bfs.get(tl).add(tn.val);
            }
            else{
                List<Integer> lvl = new ArrayList<>();
                lvl.add(tn.val);
                bfs.add(lvl);
            }
            if(tn.left!=null)
                q.add(new NodeAndLevel(tn.left, tl+1));
            if(tn.right!=null)
                q.add(new NodeAndLevel(tn.right, tl+1));
        }
        int c = 0;
        for(List<Integer> l : bfs){
            //System.out.println("level "+c+" contains :-");
            //for(Integer val : l){
            //    System.out.print(val);
            //}
            //System.out.println("");
            c++;
            res.add(l.get(l.size()-1));
        }
        return res;
    }
}
