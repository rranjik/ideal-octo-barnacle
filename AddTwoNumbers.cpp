/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    string LinkedListToString(ListNode* l1){
        string result;
        while(l1){
            result.append(to_string(l1->val));
            l1 = l1->next;
        }
        return result;
    }
    string LongerString(string a, string b){
        if(a.length()>b.length()){
            return a;
        }
        else return b;
    }
    string ShorterString(string a, string b){
        if(a.length()<=b.length()){
            return a;
        }
        else return b;
    }
    ListNode* StringsToLinkedList(string a, string b){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
         
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       string a = LinkedListToString(l1);
       string b = LinkedListToString(l2);
       cout<<"a is "<<a <<endl; 
       cout<<"b is "<<b <<endl; 
       ListNode* nn = new ListNode(0);
       return nn;
    }
};
