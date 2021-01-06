/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    unordered_set<Node*> s;
    void goUp(Node* a){
        if(!a) return;
        s.insert(a);
        goUp(a->parent);
    }
    Node* goUpAgain(Node* a){
        if(!a) return nullptr;
        if(s.find(a)!=s.end()) return a;
        return goUpAgain(a->parent);
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        goUp(p);
        return goUpAgain(q);
    }
};
