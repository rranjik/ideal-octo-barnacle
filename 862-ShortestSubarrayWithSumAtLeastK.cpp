class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> ps(n+1);
        for(int i = 0; i<n; i++){
            ps[i+1] = ps[i]+nums[i];
        }
        deque<int> q;
        int res = n+1;
        //we know this is a subarray diff problem
        //if the sum upto to this point is h
        //and a previous prefix sum is called p
        //p is valid, if h-p>=k
        //-p>=k-h
        //or p <= h-k 
        //or, in words, p is at most h-k
        for(int i = 0; i<=n; i++){
            //why is it okay to just look at the first element
            //it's the index with the smallest sum so far
            //It is maintained by the second lopp below
            while(q.size()&&ps[i]-ps[q.front()]>=k) {
                res = min(res, i-q.front()); 
                q.pop_front();
            }
            //imagine q has four elements
            //. . . 24 
            //the dots are things that arr irrelevant
            //also remember these are indexes, not values
            //if ps[24] >= ps[25]
            //that is, the sum at last index on the queue
            //is greater than the sum at the current index,
            //then it's never better
            //imagine ps[24] = 300 and ps[25] = 299
            //we want the 'last previous sum that is at least a given number'
            //last here is the first occurance, as seen backwards 
            //from the current index
            //299 is always better than 300 in this case
            //299<=300
            while(q.size()&&ps[i]<=ps[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        if(res==n+1) return -1;
        return res;
    }
};
