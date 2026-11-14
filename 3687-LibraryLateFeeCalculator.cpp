class Solution {
public:
    int lateFee(vector<int>& d) {
        int res=0;
        for(const auto & x : d){
            if(x<=0) continue;
            if(x==1) res++;
            else if(x<=5) res=res+(x*2);
            else res=res+(x*3);
        }
        return res;
    }
};
