/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode hc = head;
        ListNode tr = head;
        ListNode f = head;
        if(n==1 && head.next==null){
            return null;
        }
        for(int i = 0; i<n-1; i++){
            hc = hc.next;
        }
        System.out.println(hc.val);
        while(hc.next!=null){
            hc = hc.next;
            f=tr;
            tr= tr.next;
        }
        System.out.println(hc.val);
        System.out.println(tr.val);
        System.out.println(f.val);
        if(f==tr){
            head=head.next;
        }
        else if(f.next!=null)
        f.next= f.next.next;
        else
        f=null;
        return head;
    }
}
