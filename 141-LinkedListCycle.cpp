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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* s = head;
        ListNode* f = head->next;
        while(f&&f!=s){
            s = s->next;
            if(f->next)
                f = f->next->next;
            else f = f->next;
        }
        if(f) return true;
        else return false;
    }
};
