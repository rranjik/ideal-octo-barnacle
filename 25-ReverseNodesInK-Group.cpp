/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = nullptr;
        while(head&&k>0){
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            k--;
        }
        return prev;
    }
    /*
            ListNode tempNode = new ListNode(0);
        tempNode.next = head;
        ListNode tempHead = head;
        ListNode prev = tempNode;
        while(tempHead!=null){
            // Starting of each reversed list, it will become the last after reversing
            ListNode klast = tempHead;
            int num = k;
            // Jump k 
            while(num>0 && tempHead!=null){
                tempHead = tempHead.next;
                num--;
            }
            // If cannot reverse
            if(num!=0) {
                prev.next = klast;
                break;
            }
            // start of each reversed group
            ListNode kstart = reverse(klast,k);
            
            // Use previous's next to point to curr reversed
            prev.next = kstart;
            // Set prev to current rev end.
            prev = klast; 
        }
        return tempNode.next;
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto headc = head;
        auto prev = dummy;
        while(headc){
            auto klast = headc;
            int count = k;
            while(count>0&&headc){
                headc = headc->next;
                count--;
            }
            if(count!=0) {
                prev->next = klast;
                break;
            }
            auto kstart = reverse(klast, k);
            prev->next = kstart;
            prev = klast;
        }
        return  dummy->next;
    }
};
