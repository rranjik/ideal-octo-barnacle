/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        auto h = head;
        while(h){
            n++;
            h = h->next;
        }
        int m = n/2;
        if(!m) return nullptr;
        auto p = h;
        auto c = h;
        h = head;
        while(m){
            m--;
            p = h;
            h = h->next;
        }
        p->next = h->next;
        return head;
    }
};
