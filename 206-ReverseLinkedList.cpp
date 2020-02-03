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
    ListNode* rv(ListNode* prev, ListNode* head){
        if(!head) return prev;
        else{
            auto res = rv(head, head->next);
            head->next = prev;
            return res;
        }
    }
    ListNode* reverseList(ListNode* head) {
        //https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif
        ListNode* res = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
        //return rv(nullptr, head);
    }
};
