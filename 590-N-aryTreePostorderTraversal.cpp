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
    vector<int> postorder(Node* root) {
        stack<Node*> s1;
        stack<int> s2;
        vector<int> res;
        if(!root) return res;
        s1.push(root);
        while(!s1.empty()){
            auto n = s1.top();
            s1.pop();
            s2.push(n->val);
            for(int i = 0; i<n->children.size(); i++){
                s1.push(n->children[i]);
            }
        }
        while(!s2.empty()){
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};
