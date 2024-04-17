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
    ListNode* mergeNodes(ListNode* head) {
        auto ret = head;
        auto ls = head;
        auto curr = head;
        int res = 0;
        while(curr){
            if(curr->val){
                res+=curr->val;
                curr = curr->next;
            }else{
                curr = curr->next;
                if(!res) continue;
                ls->val = res;
                res = 0;
                ret = ls;
                ls = ls->next;
            }
        }
        ret->next = nullptr;
        return head;
    }
};
