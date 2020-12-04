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
    ListNode* rev(ListNode* h, ListNode* prev){
        if(!h) return h;
        if(!h->next){
            h->next = prev;
            return h;
        }
        auto nh = rev(h->next, h);
        h->next = prev;
        return nh;
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        auto s = head;
        auto f = s;
        ListNode* sprev = nullptr;
        while(f){
            sprev = s;
            s = s->next;
            if(f->next) f = f->next->next;
            else f = f->next;
        }
        auto l1 = head;
        if(!s) return ;
        sprev->next = nullptr;
        auto l2 = rev(s, nullptr);
        auto curr = head;
        bool one = true;
        while(l1||l2){
            //if(curr&&l2){
                //auto temp = curr->next;
                if(one){
                    if(l1)
                    l1 = l1->next;
                    curr->next = l2;
                    curr = curr->next;
                    //if(l2)
                    //l2 = l2->next;
                    one = !one;
                }else {
                    if(l2)
                    l2 = l2->next;
                    curr->next = l1;
                    curr = curr->next;
                    //if(l1)
                    //l1 = l1->next;
                    one = !one;
                }
            //}
            //if(curr&&l1){
                //auto temp = curr->next;
                //if(l2)
                //l2 = l2->next;
                //curr->next = l1;
                //curr = curr->next;
                //if(l1)
                //l1 = l1->next;
            //}
        }
    }
};
