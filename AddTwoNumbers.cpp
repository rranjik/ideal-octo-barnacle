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
    string AddStrings(string a, string b){
        //reverse(a.begin(), a.end());
        //reverse(b.begin(), b.end());
        string longer = LongerString(a, b);
        string shorter = ShorterString(a, b);
        bool carry = false;
        size_t s = 0;
        string res;
        for(const auto& digit : longer){
            int next_digit = 0;
            //if there is digits left in the shorter one
            if(s<shorter.length()){
                int lower = shorter[s] - '0';
                int upper = digit - '0';
                if(lower + upper + (carry?1:0) <10){
                    next_digit = lower + upper + (carry?1:0);
                    carry = false;
                }
                else {
                    next_digit = (lower + upper + (carry?1:0))%10;
                    carry = true;
                }
                res.append(to_string(next_digit));
            }
            else {
                int upper = digit - '0';
                if(upper + (carry?1:0) <10){
                    next_digit = upper + (carry?1:0);
                    carry = false;
                }
                else {
                    next_digit = (upper + (carry?1:0))%10;
                    carry = true;
                }
                res.append(to_string(next_digit));
            }
            s++;
        }
        if(carry)
           res.append(to_string(1));
        return res;
    }
    ListNode* StringToLinkedList(string r){
        ListNode* head = nullptr;
        ListNode* nxt = nullptr;
        for(const auto& d : r){
            ListNode* nn = new ListNode(d - '0');
            if(head == nullptr){
                head = nn;
                nxt = nn;
            }
            else{
                nxt->next = nn;
                nxt = nn;
            }
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       string a = LinkedListToString(l1);
       string b = LinkedListToString(l2);
       cout<<"a is "<<a <<endl; 
       cout<<"b is "<<b <<endl; 
       string sum = AddStrings(a , b);
       cout<<"sum is "<< sum << endl;
       return StringToLinkedList(sum);
    }
};
