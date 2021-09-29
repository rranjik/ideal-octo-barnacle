/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    int iv;
    Node* upper_bound(Node* head){
        if(!head) return nullptr;
        int ub = numeric_limits<int>::max();
        Node* ubn = nullptr;
        Node* lbn = nullptr;
        int lb = numeric_limits<int>::min();
        auto hc = head;
        do{
            //cout<<"checking hc->val = "<<hc->val<<" for ub"<<endl;
            if(hc->val>iv){
                if(hc->val<ub){
                    //cout<<"found an upper bound "<<endl;
                    ub = hc->val;
                    ubn = hc;
                }
            }
            if(hc->val==iv){
                ub = iv;
                ubn = hc->next;
            }
            if(hc->val<iv){
                if(hc->val>=lb){
                    lbn = hc->next;
                    lb = hc->val;
                }
            }
            hc = hc->next;
        }while(hc!=head);
        if(!ubn) return lbn;
        else return ubn;
    }
    Node* findPrev(Node* head, Node* ub){
        auto hc = head;
        Node* prev = nullptr;
        do{
            if(hc->next == ub){
                prev = hc;
            }
            hc=hc->next;
        }while(hc!=head||!prev);
        return prev;
    }
    void insertAfterPrevious(Node* p){
        auto oldNext = p->next;
        Node* nn = new Node(iv);
        nn->next = oldNext;
        p->next = nn;
    }
    Node* insert(Node* head, int insertVal) {
        iv = insertVal;
        if(!head){
            Node* nh = new Node(iv);
            nh->next = nh;
            return nh;
        }
        auto ub = upper_bound(head);
        cout<<"upper bound = "<<ub->val<<endl;
        auto prev = findPrev(head, ub);
        cout<<"previous = "<<prev->val<<endl;
        insertAfterPrevious(prev);
        return head;
    }
};
