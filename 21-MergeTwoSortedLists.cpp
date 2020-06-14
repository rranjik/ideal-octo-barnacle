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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        while(h1||h2){
            int a = (h1)?h1->val:numeric_limits<int>::max();
            int b = (h2)?h2->val:numeric_limits<int>::max();
            cout<<"a = "<<a<<"; b = "<<b<<endl;
            ListNode* nn = ((a<b)&&(h1))?h1:h2;
            if(nn==h1) cout<<"nn is h1"<<endl;
            else cout<<"nn is h2"<<endl;
            if(!curr)
            curr = nn;
            else {
                curr->next = nn;
                curr = curr->next;
            }
            if(!head){
                head = curr;
            }
            if(nn==h1&&(h1)) {h1 = h1->next; cout<<"h1 won "<<endl;}
            if(nn==h2&&(h2)) {h2 = h2->next; cout<<"h2 won "<<endl;}
        }
        return head;
    }
};
