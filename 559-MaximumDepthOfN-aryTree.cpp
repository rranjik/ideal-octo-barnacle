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
    int dfs(Node* root){
        if(!root) return 0;
        auto maxi = -1;
        for(int i = 0; i<root->children.size(); i++){
            maxi = max(maxi, dfs(root->children[i]));
        }
        return maxi+1;
    }
    int maxDepth(Node* root) {
        if(!root) return 0;
        return dfs(root)+1;
    }
};
