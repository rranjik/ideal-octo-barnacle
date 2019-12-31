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
        auto h = head;
        while(h!=nullptr){
            cout<<"h->val = "<<h->val<<endl;
            auto c = h;
            while(c && c->val == h->val){
                c = c->next;
            }
            h->next = c;
            h = c;
        }
        return head;
    }
};
