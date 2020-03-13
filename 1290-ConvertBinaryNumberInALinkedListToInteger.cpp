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
        if(!head){
            return head;
        } else if (!head->next){
            head->next = prev;
            return head;
        } else {
            auto h = rev(head->next, head);
            head->next = prev;
            return h;
        }
    }
    int getDecimalValue(ListNode* head) {
        ListNode* hc = head;
        while(hc){
            cout<<hc->val<<" ";
            hc=hc->next;
        }
        cout<<endl;
        ListNode* rl = rev(head, nullptr);;
        ListNode* rc = rl;
        auto res = 0;
        auto pow = 1;
        while(rc){
            cout<<rc->val<<" ";
            res+=(rc->val*pow);
            pow<<=1;
            rc=rc->next;
        }
        cout<<endl;
        return res;
    }
};
