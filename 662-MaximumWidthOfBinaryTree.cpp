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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        deque<TreeNode*> lvl;
        size_t maxWidth = 0;
        while(!q.empty()){
            lvl.clear();
            while(!q.empty()){
                lvl.push_back(q.front());
                q.pop();
            }
            auto firstNonNull = false;
            while(!firstNonNull&&lvl.size()>0){
                if(!lvl.front()) lvl.pop_front();
                else firstNonNull = true;
            }
            auto lastNonNull = false;
            while(!lastNonNull&&lvl.size()>0){
                if(!lvl.back()) lvl.pop_back();
                else lastNonNull = true;
            }
            maxWidth = max(maxWidth, lvl.size());
            while(lvl.size()){
                auto n = lvl.front();
                lvl.pop_front();
                if(n){
                    q.push(n->left);
                    q.push(n->right);
                }else {
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
        }
        return maxWidth;
    }
};
