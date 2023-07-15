class Solution {
public:
    struct Trie{
        array<shared_ptr<Trie>, 2> t;
        int cnt = 0;
        //it's given that any number in the trie 
        //is <=2*10^4 and ln2(2*10^4) = 14.2
        //which means we will never need more than 15 
        //digits any number in the input - this also 
        //determines the maximum height of the trie
        void insert(int n, int i = 1<<14){
            cnt++;
            bool b = n&i;
            if(!t[b]) t[b] = make_shared<Trie>();
            if(i>0) t[b]->insert(n, i>>1);
        }
        int countLess(int n, int l, int i = 1<<14){
            bool n_b = n&i;
            bool l_b = l&i;
            bool x = (n^l)&i;
            
            //if limit bit is 1 we can count everything
            //in the n_b subtree; because we are very sure 
            //these are smaller; two cases: 
            //case 1: limit = 1; n_b = 0
            //        0(n_b subtree)^0(number) = 0<=1
            //case 2: limit = 1; n_b = 1
            //        1(n_b subtree)^1(number) = 0<=1
            int othertree = x?0:1;//opp of where we are going
            int num_bit = n_b?1:0;//val of number here
            int xorr = othertree^num_bit;//xor opp and num_bit here
            int lim = l_b?1:0;//get the limit
            return (lim>=xorr?//if xorr <= limit use othertree 
                    (t[othertree]?t[othertree]->cnt:0):0)+
                //we need to decide where to move
                //legend has it that we always move in the direction
                //of x. Please see table
                (t[x]?t[x]->countLess(n, l, i>>1):0);
        }
    };
    int countPairs(vector<int>& nums, int low, int high) {
        Trie r;
        int res = 0;
        for(auto& n : nums){
            res += r.countLess(n, high+1) - r.countLess(n, low);
            r.insert(n);
        }
        return res;
    }
    /*
    have limit 
    0    0     if subtree is 1 then xor is 1 and becomes greater so move to 0 which is 0^0
               but there's a question of a previous 1 on the number somewhere before this 
               index causing this number to be really lesser. Imagine the following:
                         i    
               number1: 000000111111
               limit:   100000000001
               yet2:    111110000001
               yet1:    101000000000
               counted1:011111111111
               counted2:000000000001
               Given this i everything starting with 0 in the previous position was 
               counted already 
    0    1
    1    0
    0    1
    */

};
