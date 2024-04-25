class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(!num) return {-1, 0, 1};
        long long l = 0; 
        long long r = num-1;
        while(l<=r){
            cout<<"l = "<<l<<" r = "<<r<<endl;
            long long m = l+(r-l)/2;
            auto c = m + (m-1) + (m-2);
            if(c==num){
                return {(m-2), (m-1), m};
            }
            if(c<num){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return {};
    }
};
