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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head) return head;
        while(fast){
            if(fast->next){
                fast = fast->next->next;
            }else{
                return slow;
            }
            slow = slow->next;
        }
        return slow;
    }
};
