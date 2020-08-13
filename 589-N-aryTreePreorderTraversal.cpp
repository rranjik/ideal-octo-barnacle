/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            auto n = s.top();
            s.pop();
            res.push_back(n->val);
            for(auto it = n->children.rbegin(); it!=n->children.rend(); it++){
                s.push(*it);
            }
        }
        return res;
    }
};
