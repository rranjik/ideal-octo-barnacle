/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node*, NodeCopy*> cp;
    NodeCopy* dfs1(Node* root){
        if(root){
            NodeCopy* nn = new NodeCopy(root->val);
            cp[root] = nn;
            nn->left = dfs1(root->left);
            nn->right = dfs1(root->right);
            return nn;
        }
        return nullptr;
    }
    void dfs2(Node* root){
        if(root){
            auto c = cp[root];
            if(root->random)
            c->random = cp[root->random];
            else c->random = nullptr;
            dfs2(root->left);
            dfs2(root->right);
        }
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        auto res = dfs1(root);
        dfs2(root);
        return res;
    }
};
