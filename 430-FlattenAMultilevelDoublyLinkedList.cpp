/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* dfs(Node* head){
        if(!head) return nullptr;
        auto nn = new Node(head->val);
        auto nnc = nn;
        if(head->child){
            Node* children = nullptr;
            children = dfs(head->child);
            nn->next = children;
            children->prev = nn;
            while(nn->next) nn = nn->next;
        }
        auto next = dfs(head->next);
        nn->next = next;
        if(next) next->prev = nn;
        return nnc;
    }
    Node* flatten(Node* head) {
        return dfs(head);
    }
};
