/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string ll;
    void dfs(TreeNode* root, string curr, bool& res){
        if(!root) return;
        curr+=to_string(root->val);
        curr+="-";
        if(curr.find(ll)!=string::npos) res|=true;
        if(!res){
            dfs(root->left, curr, res);
            dfs(root->right, curr, res);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        auto h = head;
        while(h){
            ll+=to_string(h->val);
            ll+="-";
            h = h->next;
        }
        bool res = false;
        string curr;
        dfs(root, curr, res);
        return res;
    }
};
