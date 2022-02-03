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
    void dfs(int s){
        cout<<"s = "<<s<<endl;
        v[s] = true;
        for(const auto& a : adjl[s]){
            if(!v[a]){
                dfs(a);
            }
        }
    }
    unordered_map<int, vector<int>> adjl;
    unordered_map<int, bool> v;
    int numComponents(ListNode* head, vector<int>& G) {
        for(const auto& g : G){
            adjl[g] = vector<int>();
            v[g] = false;
        }
        auto h = head;
        while(head){
            if(head->next){
                if(adjl.find(head->val)!=adjl.end()
                   &&adjl.find(head->next->val)!=adjl.end()){
                    adjl[head->val].push_back(head->next->val);
                    //adjl[head->next->val].push_back(head->val);
                }
            }
            head = head->next;
        }
        for(const auto& l : adjl){
            cout<<l.first;
            for(const auto& n : l.second){
                cout<<"->"<<n;
            }
            cout<<endl;
        }
        int res{};
        while(h){
            if(adjl.find(h->val)!=adjl.end()){
                if(!v[h->val]){
                    cout<<"new call "<<h->val<<endl;
                    dfs(h->val);
                    res++;
                }
            }
            h = h->next;
        }
        return res;
    }
};
