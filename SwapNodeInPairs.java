/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head==null || head.next==null) return head;
        else{
            ListNode n = head.next;//we will return this eventually
            //head.next has to change
            head.next = swapPairs(head.next.next); //to the new head returned
            n.next = head;
            return n;
        }
    }
}
