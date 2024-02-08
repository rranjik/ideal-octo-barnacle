/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    unordered_map<Node*, bool> v;
    void dfs1(Node* r){
        if(v[r]) return;
        v[r] = true;
        m[r] = new Node(r->val);
        for(const auto& c : r->neighbors){
            dfs1(c);
        }
    }
    void dfs2(Node* r){
        if(v[r]) return;
        v[r] = true;
        for(const auto& c : r->neighbors){
            m[r]->neighbors.push_back(m[c]);
            dfs2(c);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        dfs1(node);
        v.clear();
        dfs2(node);
        return m[node];
    }
};
