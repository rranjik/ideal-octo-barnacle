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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pa = headA;
        auto pb = headB;
        while(pa!=pb){
            pa = !pa?headB:pa->next;
            pb = !pb?headA:pb->next;
        }
        return pa;
    }
};
