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
    ListNode* kthFromBeginning(ListNode* head){
        int i = 1;
        while(i<k){
            head = head->next;
            i++;
        }
        return head;
    }
    ListNode* kthFromEnd(ListNode* head){
        int i = 0;
        ListNode* l;
        ListNode* t;
        t = head;
        l = head;
        while(i<k){
            l = l->next;
            i++;
        }
        while(l){
            t = t->next;
            l = l->next;
        }
        return t;
    }
    int k;
    ListNode* swapNodes(ListNode* head, int k) {
        this->k = k;
        auto one = kthFromBeginning(head);
        cout<<"one = "<<one->val<<endl;
        auto two = kthFromEnd(head);
        auto temp = one->val;
        one->val = two->val;
        two->val = temp;
        return head;
    }
};
