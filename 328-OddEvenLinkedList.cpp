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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ol = nullptr;
        ListNode* el = nullptr;
        if(head){
            ol = head;
            el = head->next;
        }
        ListNode* nolm = nullptr;
        if(el){
            nolm = el->next;
        }
        auto res = ol;
        auto elh = el;
        while(nolm){
            ol->next = nolm;
            el->next = nolm->next;
            ol = ol->next;
            el = el->next;
            if(el)
                nolm = el->next;
            else nolm = nullptr;
        }
        if(ol)
            ol->next = elh;
        return res;
    }
};
