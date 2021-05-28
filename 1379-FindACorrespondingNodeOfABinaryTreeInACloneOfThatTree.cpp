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
    string find(TreeNode* root, TreeNode* parent){
        if(!root) return "";
        string res;
        if(root==target){
            if(parent){
                if(root==parent->left)
                    res+='l';
                else res+='r';
                return res;
            }else return res;
        }
        auto l = find(root->left, root);
        //cout<<"left of "<<root->val<<" returned "<<l<<endl;
        auto r = find(root->right, root);
        //cout<<"right of "<<root->val<<" returned "<<r<<endl;
        if(l.size()>0) res+=("l"+l);
        if(r.size()>0) res+=("r"+r);
        return res;
    }
    TreeNode* res;
    TreeNode* target;
    void traverse(string directions, TreeNode* root){
        if(!directions.size()){
            res = root;
            return;
        }
        if(directions[0]=='l'){
            auto leftoverdirections = directions;
            leftoverdirections.erase(leftoverdirections.begin());
            traverse(leftoverdirections, root->left);
        }else{
            auto leftoverdirections = directions;
            leftoverdirections.erase(leftoverdirections.begin());
            traverse(leftoverdirections, root->right);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;
        auto dir = find(original, nullptr);
        cout<<"dir = "<<dir<<endl;
        
        if(dir.size()){
            dir.pop_back();
        }
        traverse(dir, cloned);
        return res;
    }
};
