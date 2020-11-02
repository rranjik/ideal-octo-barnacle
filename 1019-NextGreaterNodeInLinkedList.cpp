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
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return vector<int>();
        auto h = head;
        auto hc = h;
        int size = 0;
        while(hc){
            size++;
            hc = hc->next;
        }
        vector<int> res(size);
        stack<pair<ListNode*, int>> stk;
        int count = 0;
        while(h){
            while(!stk.empty()&&stk.top().first->val<h->val){
                res[stk.top().second] = h->val;
                stk.pop();
            }
            stk.push({h, count});
            count++;
            h = h->next;
        }
        return res;
    }
};
