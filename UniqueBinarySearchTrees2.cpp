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
    vector<TreeNode*> gt(vector<int> choices){
        vector<TreeNode*> res;
        if(choices.size()==0){
            res.push_back(nullptr);
            return res;
        }
        else if(choices.size()==1){
            TreeNode* root = new TreeNode(choices[0]);
            res.push_back(root);
            return res;
        }
        else{
            for(int i = 0; i<choices.size(); i++){
                auto left = gt(vector<int>(choices.begin(), choices.begin()+i));
                auto right = gt(vector<int>(choices.begin()+i+1, choices.end()));
                for(const auto& l : left){
                    for(const auto& r : right){
                        TreeNode* root = new TreeNode(choices[i]);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode*> res;
            return res;
        }
        vector<int> c;
        for(int i = 1; i<=n; i++)
            c.push_back(i);
        return gt(c);   
    }
};
