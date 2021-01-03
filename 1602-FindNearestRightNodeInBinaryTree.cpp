/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        vector<TreeNode*> l;
        l.push_back(root);
        TreeNode* res = nullptr;
        while(l.size()){
            vector<TreeNode*> nextl;
            auto s = l.size();
            for(int i = 0; i<s; i++){
                if(u == l[i]){
                    if(i<s-1) return l[i+1];
                    else return nullptr;
                }
                if(l[i]->left) nextl.push_back(l[i]->left);
                if(l[i]->right) nextl.push_back(l[i]->right);
            }
            l = nextl;
        }
        return nullptr;
    }
};
