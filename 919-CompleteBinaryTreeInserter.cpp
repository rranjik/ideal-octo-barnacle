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
class CBTInserter {
public:
    vector<int> arr;
    TreeNode* root;
    void bfs(TreeNode* r){
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty()){
            auto t = q.front(); q.pop();
            arr.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    CBTInserter(TreeNode* root) {
        this->root = root;
        bfs(root);
    }
    
    int insert(int v) {
        arr.push_back(v);
        return arr[arr.size()/2-1];
    }
    
    TreeNode* get_root() {
        queue<TreeNode*> q;
        int i = 0;
        auto res =new TreeNode(arr[i]); 
        q.push(res);
        i++;
        while(i<arr.size()){
            auto p = q.front();q.pop();
            auto l = new TreeNode(arr[i]);
            p->left = l;
            q.push(l);
            i++;
            if(i<arr.size()){
                auto r = new TreeNode(arr[i]);
                p->right = r;
                q.push(r);
                i++;
            }
        }
        return res;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
