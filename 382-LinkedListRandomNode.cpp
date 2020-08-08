/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    size_t len{0};
    //last head
    ListNode* lh;
    //true head
    ListNode* th;
    map<int, int> f;
    int c = 0;
    Solution(ListNode* head) {
        th = head;
        lh = head;
        auto h = head;
        ListNode* prev = nullptr;
        while(h){
           len++;
           prev = h;
           h=h->next;
        }
        prev->next = head;
        cout<<"len = "<<len<<endl;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        //c++;
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(0,len-1); 
        size_t n = dist(rng);
        //cout<<"n = "<<n<<endl;
        while(n){
            lh = lh->next;
            //if(!lh) lh = th;
            //else lh = lh->next;
            n--;
        }
        //if(!lh) lh = th;
        //f[lh->val]++;
        //if(c>4600){
        //    for(auto it = f.begin(); it!=f.end(); it++)
        //        cout<<it->first<<"-"<<it->second<<"; ";
        //    cout<<endl;
        //}
        return lh->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
