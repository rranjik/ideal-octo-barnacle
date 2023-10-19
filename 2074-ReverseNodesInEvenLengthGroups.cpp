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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> l;
        auto h = head;
        while(h){
            l.push_back(h->val);
            h = h->next;
        }
        int i = 0;
        int g = 1;
        cout<<"read "<<endl;
        while(i<l.size()){
            int b = i;
            int al = 0;
            int og = g;
            while(i<l.size()&&g){
                i++;
                al++;
                g--;
            }
            cout<<"al = "<<al<<endl;
            if(al%2==0){
                cout<<"rev from "<<b<<" to "<<b+al<<endl;
                reverse(l.begin()+b, l.begin()+b+al);
            }
            g = og+1;
        }
        h = head;
        i = 0;
        while(h){
            h->val = l[i];
            h = h->next;
            i++;
        }
        return head;
    }
};
