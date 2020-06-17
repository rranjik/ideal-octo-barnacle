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
    size_t length(ListNode* head){
        int i = 0;
        while(head){
            i++;
            head=head->next;
        }
        return i;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = length(root);
        vector<ListNode*> res;
        int ex = (n%k);
        ListNode* nh = root;
        while(ex){
            int num = (n/k)+1;
            ListNode* curr = nullptr;
            ListNode* hh = nullptr;
            while(num){
                if(!curr){
                    curr=nh;
                    hh=curr;
                }else{
                    curr->next=nh;
                    curr = curr->next;
                }
                nh=nh->next;
                num--;
            }
            if(nh) nh = curr->next;
            curr->next=nullptr;
            res.push_back(hh);
            ex--;
        }
        auto l = (k-(n%k));
        while(l){
            int num = (n/k);
            ListNode* curr = nullptr;
            ListNode* hh = nullptr;
            while(num){
                if(!curr){
                    curr=nh;
                    hh=curr;
                }else{
                    curr->next=nh;
                    curr = curr->next;
                }
                nh=nh->next;
                num--;
            }
            if(nh) nh= curr->next;
            if(curr) curr->next=nullptr;
            res.push_back(hh);
            l--;
        }
        return res;
    }
};
