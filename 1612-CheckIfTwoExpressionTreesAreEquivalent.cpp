/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<char, int> c1;
    unordered_map<char, int> c2;
    auto dfs(Node* root, unordered_map<char, int>& c){
        if(!root) return;
        if(root->val!='+'){
            c[root->val-'a']++;
        }
        dfs(root->left, c);
        dfs(root->right, c);
    }
    bool checkEquivalence(Node* root1, Node* root2) {
        dfs(root1, c1); dfs(root2, c2);
        return c1==c2;
    }
};
