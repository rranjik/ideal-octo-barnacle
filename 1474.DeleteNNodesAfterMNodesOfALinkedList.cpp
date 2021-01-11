/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* traveN(ListNode* n){
        int i = 1;
        while(i<=N+1){
            if(n)
            n = n->next;
            else return nullptr;
            i++;
        }
        return n;
    }
    int N;
    ListNode* deleteNodes(ListNode* head, int M, int N) {
        this->N = N;
        int i = 1;
        auto res = head;
        while(head){
            while(i<M){
                if(head)
                head = head->next;
                else return res;
                i++;
            }
            auto here = head;
            auto afterN = traveN(head);
            if(here)
                here->next = afterN;
            head = afterN;
            i = 1;
        }
        return res;
    }
};
