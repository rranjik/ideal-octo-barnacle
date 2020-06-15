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
    bool isPal(const vector<int>& s, int i, int j){
        cout<<"i = "<<i<<"; j = "<<j<<endl;
        if((i==j)||(i>j))
            return true;
        if(s[i]==s[j]){
            return isPal(s, i+1, j-1);
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        //TODO: constant spacd
        vector<int> s;
        auto h = head;
        while(h){
            s.push_back(h->val);
            h = h->next;
        }
        return isPal(s, 0, s.size()-1);
    }
};
