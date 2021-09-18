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
    ListNode* rev(ListNode* head, ListNode* prev){
        if(!head) return head;
        if(!head->next){
            head->next = prev;
            return head;
        }
        auto h = rev(head->next, head);
        head->next = prev;
        return h;
    }
    ListNode* plusOne(ListNode* head) {
        auto revh = rev(head, nullptr);
        ListNode* prev = nullptr;
        auto revhc = revh;
        int carry = 0;
        bool one = true;
        while(revhc){
            int d = revhc->val;
            if(one){d++; one = false;}
            int nd = d+carry;
            revhc->val = nd%10;
            if(nd>=10){
                carry=1;
            }else carry = 0;
            prev = revhc;
            revhc = revhc->next;
        }
        if(carry){
            ListNode* c = new ListNode(carry);
            prev->next = c;
        }
        return rev(revh, nullptr);
    }
};
