class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
        int c{};
        vector<int> res;
        for(int i = A.size()-1; i>=0; i--){
            auto kd = k%10;
            k=k/10;
            int d = (A[i]+c+kd)%10;
            c = (A[i]+c+kd)/10;
            res.push_back(d);
        }
        while(k){
            auto kd = k%10;
            k=k/10;
            int d = (c+kd)%10;
            c = (c+kd)/10;
            res.push_back(d);
        }
        if(c) res.push_back(c);
        reverse(res.begin(), res.end());
        return res;
    }
};
