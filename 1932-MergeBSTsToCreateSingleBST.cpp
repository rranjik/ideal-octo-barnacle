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
    bool traverseAndAttach(TreeNode* r, unordered_map<int, TreeNode*>& m, 
                          int min_left = INT_MIN, int max_right = INT_MAX){
        //an empty tree is a valid a BST
        if(!r) return true;
        cout<<"r is "<<r->val<<" m.size() = "
<<m.size()<<" m_l = "<<min_left<<"  m_r = "<<max_right<<endl;
        //is it a leaf ?
        if(!r->left&&!r->right){
            auto it = m.find(r->val);
            //found something 
            if(it!=m.end()){
                r->left = it->second->left;
                //make sure there's a left elem (it could've been nullptr)
                if(it->second->left) {
                    //if there's a left element
                    int leftRoot = it->second->left->val;
                    //then it must be strictly less that the current root
                    //and stricty greater than the current running max
                    if(leftRoot>=r->val||leftRoot<=min_left) return false;
                }
                //avoiding leaks - okay to leave this assignment out 
                it->second->left = nullptr;
                
                r->right = it->second->right;
                if(it->second->right) {
                    int rightRoot = it->second->right->val;
                    if(rightRoot>=max_right||rightRoot<=r->val) return false;
                }
                it->second->right = nullptr;
                m.erase(it);
            }
        }
        //try to attach anything to the left and right with the appropriate 
        //left and right margins
        return traverseAndAttach(r->left, m, min_left, r->val) &&
            traverseAndAttach(r->right, m, r->val, max_right);
    }
    //note that we depend on a lot of constraints from the question
    //not such thing as 
    //    3
    //   / \
    //  2  null
    // / \
    //1  null
    //everything is either to the left of root, or the right of root
    //or nowhere else
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, int> c;
        for(const auto& it : trees){
            m[it->val] = it;
            c[it->val]++;
            if(it->left) c[it->left->val]++;
            if(it->right) c[it->right->val]++;
        }
        for(const auto& it : trees){
            if(c[it->val]==1){
                cout<<"root is "<<it->val<<endl;
                //depends on uniqueness (there's not other root with value it->val)
                m.erase(it->val);
                auto worked = traverseAndAttach(it, m);
                auto allAttached = m.size()==0;
                //if everything satisfied the constraints and 
                //there's no root left
                if(worked&&allAttached) return it;
                break; //or return nullptr;
            }
        }
        return nullptr;
    }
};
