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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* start = head;
        ListNode* end = head;
        int c = 1;
        auto hc = head;
        while(c<left){
            hc = hc->next;
            start = hc;
            c++;
        }
        vector<int> bw;
        while(c<=right){
            end = hc;
            bw.push_back(hc->val);
            hc = hc->next;
            c++;
        }
        for(const auto& n : bw) cout<<n<<" "; cout<<endl;
        reverse(bw.begin(), bw.end());
        int i = 0;
        while(start!=end){
            start->val = bw[i];
            i++;
            start = start->next;
        }
        start->val = bw[i];
        return head;
    }
};
