/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        auto n = root->next;
        while(n){
            if(n->left){
                n = n->left;
                break;
            }
            if(n->right){
                n = n->right;
                break;
            }
            n = n-> next;
        }
        if(root->right) root->right->next = n;
        if(root->left) root->left->next = (root->right?root->right:n);
        connect(root->right);
        connect(root->left);
        return root;
    }
};
