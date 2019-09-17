/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> mp = new HashMap<>();
        Node hc = head;
        while(hc!=null){
            mp.put(hc, new Node());
            hc=hc.next;
        }
        hc = head;
        while(hc!=null){
            Node c = mp.get(hc);
            c.val = hc.val;
            c.next = mp.get(hc.next);
            c.random = mp.get(hc.random);
            hc = hc.next;
        }
        return mp.get(head);
    }
}
