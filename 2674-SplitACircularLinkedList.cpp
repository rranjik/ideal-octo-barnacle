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
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        vector<ListNode*> res;
        auto tail = list;
        auto head = list;
        auto first = list;
        auto firstc = list;
        int n = 1;
        while(tail->next!=head){
            n++;
            tail = tail->next;
        }
        int flen = ceil((1.0*n)/2);
        ListNode* second = nullptr;
        for(int i = 0; i<flen-1; i++){
            first = first->next;
        }
        second = first->next;
        auto secondc = first->next;
        first->next = head;
        while(secondc->next!=head){
            secondc = secondc->next;
        }
        secondc->next = second;
        return {head, second};
    }
};
