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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(!k) return head;
        auto n = 0;
        ListNode* h = head;
        ListNode* l = nullptr;
        while(h){ l = h; h = h->next; n++; }
        cout<<"l = "<<l->val<<endl;
        cout<<"n = "<<n<<endl;
        k%=n;
        auto rot = n-k;
        cout<<"after reducing n = "<<k<<endl;
        cout<<"rot = "<<rot<<endl;
        if(!k) return head;
        ListNode* ret = head;
        ListNode* prev = nullptr;
        while(rot){
            prev = ret;
            ret = ret->next;
            cout<<" prev = "<<prev->val<<endl;
            if(ret) cout<<" ret = "<<ret->val<<endl;
            rot--;
        }
        l->next = head;
        if(prev!=l) prev->next = nullptr;
        return ret;
    }
};
