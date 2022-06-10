/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void in(Node* r, vector<Node*>& l){
        if(!r) return;
        in(r->left, l);
        l.push_back(r);
        in(r->right, l);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        vector<Node*> v;
        in(root, v);
        for(int i = 0; i<v.size()-1; i++){
            v[i]->right = v[i+1];
            v[i+1]->left = v[i];
        }
        v[v.size()-1]->right = v[0];
        v[0]->left = v[v.size()-1];
        return v[0];
    }
};
