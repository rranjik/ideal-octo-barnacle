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
        if(root == nullptr)
            return nullptr;
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = (root->next ? root->next->left :nullptr);
        connect(root->left);
        connect(root->right);
        return root;
    }
};
