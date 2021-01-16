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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        if(!root||!p) return nullptr;
        TreeNode* prev = nullptr;
        while(!s.empty()||root){
            if(root){
                if(root) cout<<"pushing "<<root->val<<endl;
                s.push(root);
                root = root->left;
            }else{
                //if(s.empty()) return nullptr;
                auto n = s.top();
                s.pop();
                if(prev == p) return n;
                cout<<n->val<<" "<<endl;
                prev = n;
                root = n->right;
            }
        }
        return nullptr;
    }
};
