/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        Map<ListNode, Integer> m = new HashMap<>();
        ListNode hc = head;
        int i = 0;
        while(hc!=null){
            if(m.containsKey(hc)){
                return hc;
            }
            else 
                m.put(hc, i);
            i++;
            hc=hc.next;
        }
        return null;
    }
}
