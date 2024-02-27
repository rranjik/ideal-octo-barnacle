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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        auto one = p; auto two = q;
        while(one!=two){
            if(!one) one = q;
            else one = one->parent;
            if(!two) two = p;
            else two = two->parent;
        }
        return one;
    }
};
