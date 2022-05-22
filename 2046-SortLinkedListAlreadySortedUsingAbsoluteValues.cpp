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
    ListNode* sortLinkedList(ListNode* head) {
        auto prev = head;
        auto cur = head;
        while(cur){
            //cout<<"cur = "<<cur->val<<endl;
            //cout<<"prev = "<<cur->val<<endl;
            //cout<<"head = "<<cur->val<<endl;
            if(cur->val<0){
                if(head!=cur){
                    prev->next = cur->next;
                    cur->next =head;
                    head = cur;
                    cur = prev->next;
                }else{
                    prev = cur;
                    cur = cur->next;
                }
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
