/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class PNode{
public:
    int val;
    int index;
    PNode(int _val, int _index) : val(_val), index(_index) {}
};
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lsts) {
        auto lists = lsts;
        auto PNodeCompare = [](const PNode& p1, const PNode& p2){
            //cout<<"PNodeCompare p1("<<p1.val<<", "<<p1.index<<"), p2("<<p2.val<<", "<<p2.index<<"): returns "<<(p1.val>p2.val)<<endl;
            return p1.val>p2.val;
        };
        priority_queue<PNode, vector<PNode>, decltype(PNodeCompare)> q(PNodeCompare);
        for(int i = 0; i<lists.size(); i++){
            if(!lists[i]){}
            else{
                q.push(PNode(lists[i]->val, i));
                //cout<<"pushed "<<lists[i]->val<<endl;
                lists[i] = lists[i]->next;
            }
        }
        ListNode* curr = nullptr;
        ListNode* res = nullptr ;
        while(!q.empty()){
            auto e = q.top();
            //cout<<"popped "<<e.val<<endl;
            q.pop();
            if(lists[e.index]){
                q.push(PNode(lists[e.index]->val, e.index));
                //cout<<"pushed "<<lists[e.index]->val<<endl;
                lists[e.index] = lists[e.index]->next;
            }
            ListNode* ln = new ListNode(e.val);
            if(!curr) {curr = ln; res = curr;}
            else { curr->next =ln; curr = curr->next;}
        }
        return res;
    }
};
