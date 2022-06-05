/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* treeMinimum(Node* n){
        while(n->left) n = n->left;
        return n;
    }
    Node* inorderSuccessor(Node* node) {
        if(node->right) return treeMinimum(node->right);
        auto y = node->parent;
        while(y&&node==y->right){
            node = y;
            y = y->parent;
        }
        return y;
    }
};
