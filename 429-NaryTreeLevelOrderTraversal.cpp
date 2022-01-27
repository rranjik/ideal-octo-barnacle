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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            auto len = q.size();
            vector<int> thislevel;
            for(int i = 0; i<len; i++){
                auto n = q.front();
                thislevel.push_back(n->val);
                q.pop();
                for(const auto& c : n->children){
                    q.push(c);
                }
            }
            res.push_back(thislevel);
        }
        return res;
    }
};
