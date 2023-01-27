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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ath{nullptr};
        ListNode* bth{nullptr};
        int i = 0;
        auto list1c = list1;
        while(list1c){
            if(i==a-1) ath = list1c;
            if(i==b+1) bth = list1c;
            list1c = list1c->next;
            i++;
        }
        if(ath) ath->next = list2;
        auto lastin2 = list2;
        auto list2c = list2;
        while(list2c){
            lastin2 = list2c;
            list2c = list2c->next;
        }
        lastin2->next = bth;
        return list1;
    }
};
