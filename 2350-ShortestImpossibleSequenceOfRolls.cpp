class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int, int> occ;
        int cntk = 0;
        int res = 0;
        for(const auto& r : rolls){
            //cout<<"r = "<<r<<endl;
            if(occ[r]==res){
                occ[r]++;
                cntk++;
                if(cntk==k){
                    cntk = 0;
                    res++;
                }
            }
            //cout<<"cntk = "<<cntk<<endl;
        }
        return res+1;
    }
};
