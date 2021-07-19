class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        multiset<int> bob(begin(B), end(B));
        int asum = 0;
        for(const auto& a : A){
            asum+=a;
        }
        int bsum = 0;
        for(const auto& b : B){
            bsum+=b;
        }
        int delta = (bsum-asum)/2;
        
        for(int i = 0; i<A.size(); i++){
            if(bob.find(A[i]+delta)!=bob.end()){
                return {A[i], A[i]+delta};
            }
        }
        return{};
    }
};
