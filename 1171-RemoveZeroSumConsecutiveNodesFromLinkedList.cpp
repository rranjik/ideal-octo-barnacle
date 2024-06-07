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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return nullptr;
        unordered_map<int, ListNode*> m;
        while(head&&head->val==0) head = head->next;
        auto h = head;
        int sum = 0;
        while(h){
            if(m.find(sum+h->val)!=m.end()){
                m[sum+(h->val)]->next = h->next;
                //cout<<"matching "<<endl;
                return removeZeroSumSublists(head);
            }
            sum+=(h->val);
            if(sum==0) return removeZeroSumSublists(h->next);
            m[sum] = h;
            //cout<<"sum  = "<<sum<<" at "<<h->val<<endl;
            h = h->next;
        }
        return head;
    }
};
