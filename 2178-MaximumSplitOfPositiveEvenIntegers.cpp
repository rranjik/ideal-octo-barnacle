class Solution {
public:
    vector<long long> maximumEvenSplit(long long f) {
        if(f%2)
            return {};
        long long e = 2;
        vector<long long> res;
        long long curr = 0;
        //keep adding unique elements
        //until we reach f
        while((curr+e)<=f){
            res.push_back(e);
            curr+=e;
            e+=2;
        }
        
        //f-curr is left over
        //adding this to maintains uniqueness
        //all elements added so far is unique and
        //increasing the last element just preseveres it
        res[res.size()-1]+=(f-curr);
        return res;
    }
};
