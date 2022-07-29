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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        _serialize(root, res);
        return res;
    }
    
    void _serialize(Node* root,string& res){
        if(!root) return;
        res+=" "+to_string(root->val)+" "+to_string(root->children.size());
        for(const auto& c : root->children) _serialize(c, res);
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(!data.size()) return nullptr;
        stringstream ss(data);
        return _deserialize(ss);
    }
    
    Node* _deserialize(stringstream& ss){
        if(ss.eof())return nullptr;
        auto root= new Node(0);
        int numChildren = 0;
        ss>>root->val>>numChildren;
        for(int i = 0; i<numChildren; i++) root->children.push_back(_deserialize(ss));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
