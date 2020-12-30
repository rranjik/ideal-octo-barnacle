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
    Node* dfs(Node* root){
        if(root){
            Node* res = new Node(root->val);
            for(const auto& n : root->children){
                res->children.push_back(dfs(n));
            }
            return res;
        }else return nullptr;
    }
    Node* cloneTree(Node* root) {
        return dfs(root);
    }
};
