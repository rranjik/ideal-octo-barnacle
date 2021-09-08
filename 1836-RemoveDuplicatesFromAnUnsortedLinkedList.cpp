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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        auto h = head;
        unordered_map<int, int> f;
        int i = 0;
        while(h){
            if(f.find(h->val)==f.end()){
                f[h->val] = i;
            }else{
                f[h->val] = -1;
            }
            i++;
            h = h->next;
        }
        vector<pair<int, int>> v;
        for(const auto& it : f){
            if(it.second!=-1)
                v.push_back({it.second, it.first});
        }
        sort(begin(v), end(v));
        auto prev = head;
        h = head;
        for(const auto& n : v){
            h->val = n.second;
            prev = h;
            h = h->next;
        }
        if(prev==h) return nullptr;
        prev->next = nullptr;
        return head;
    }
};
