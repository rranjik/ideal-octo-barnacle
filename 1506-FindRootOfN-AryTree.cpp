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
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node*, int> c;
        unordered_map<int, int> count;
        for(int i = 0; i<tree.size(); i++){
            //cout<<" i = "<<i<<endl;
            if(tree[i]){
                if(c.find(tree[i])==c.end()) c[tree[i]] = 0;
                for(int j = 0; j<tree[i]->children.size(); j++){
                    cout<<tree[i]->children[j]->val<<" has a parent "<<endl;
                    c[tree[i]->children[j]]++;
                    cout<<"c["<<tree[i]->children[j]->val<<"] = "<<c[tree[i]->children[j]]<<endl;
                }
            }
        }
        Node* res;
        for(const auto& it : c){
            cout<<"node = "<<it.first->val<<" p = "<<it.second<<endl;
            if(!it.second) res = it.first;
        }
        //return res;
    }
};
