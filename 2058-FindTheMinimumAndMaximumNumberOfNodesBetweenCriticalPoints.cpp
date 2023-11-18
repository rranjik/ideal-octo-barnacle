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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        auto h = head;
        while(h){
            v.push_back(h->val);
            h = h->next;
        }
        vector<bool> c(v.size());
        int last = -1;
        int mi = v.size();
        int ma = 0;
        int first = -1;
        for(int i = 1; i<v.size()-1; i++){
            if(v[i-1]>v[i]&&v[i]<v[i+1]){
                c[i] = true;
                if(last==-1) first = i;
                if(last!=-1&&mi>(i-last)) mi = i-last;
                last = i;
            }else if(v[i-1]<v[i]&&v[i]>v[i+1]){
                c[i] = true;
                if(last==-1) first = i;
                if(last!=-1&&mi>(i-last)) mi = i-last;
                last = i;
            }
        }
        if(last==-1||first==-1||last==first) return {-1, -1};
        ma = last-first;
        return {mi, ma};
    }
};
