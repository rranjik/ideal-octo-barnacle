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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        auto h = head;
        ListNode* curr = nullptr;
        ListNode* ret = nullptr;
        while(head){
            bool repeat = false;
            while(head->next&&head->next->val==head->val){
                repeat = true;
                head=head->next;
            }
            if(!repeat){
                if(!curr){
                    curr = new ListNode(head->val);
                    ret = curr;
                }else{
                    curr->next = new ListNode(head->val);
                    curr = curr->next;
                }
            }
            head = head->next;
        }
        return ret;
    }
};
