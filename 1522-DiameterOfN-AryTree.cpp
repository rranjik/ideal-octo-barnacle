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
    int dia{};
    int dfs(Node* n){
        if(!n) return 0;
        int through{};
        int res{};
        vector<int> heights;
        for(const auto& c : n->children){
            heights.push_back(dfs(c));
        }
        sort(heights.begin(), heights.end());
        cout<<n->val<<": ";
        for(const auto& h : heights) cout<<h<<" ";
        cout<<endl;
        auto s = heights.size();
        if(heights.size()>=2) {
            through = heights[s-1]+heights[s-2];
        }
        dia = max(dia, through);
        if(heights.size()) res = heights[s-1];
        cout<<"through at "<<n->val<<" = "<<through<<endl;
        cout<<"n = "<<n->val<<" returns "<<res<<endl;
        dia = max(dia, res);
        return res+1;
    }
    int diameter(Node* root) {
        dfs(root);
        return dia;
    }
};
