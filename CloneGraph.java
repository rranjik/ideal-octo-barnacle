/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    Map<Node, Node> m = new HashMap<>();
    public Node cloneGraph(Node node) {
        if(node==null){
            return null;
        }
        Queue<Node> q = new LinkedList<>();
        m.put(node , new Node(node.val, new ArrayList<>()));
        q.add(node);
        while(q.peek()!=null){
            Node n = q.peek();
            q.remove();
            n.neighbors.forEach(neighbor->{
                if(!m.containsKey(neighbor)){
                    m.put(neighbor, new Node(neighbor.val, new ArrayList<>()));
                    q.add(neighbor);
                }
                m.get(n).neighbors.add(m.get(neighbor));
            });
        }
        return m.get(node);
    }
}
