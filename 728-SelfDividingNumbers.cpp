class Solution {
public:
    bool check(int n){
        int nc = n;
        vector<int> ds;
        while(n){
            int d=n%10;
            n/=10;
            ds.push_back(d);
        }
        for(int i = 0;i <ds.size(); i++){
            if(!ds[i]||(nc%ds[i]))
               return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i<=right; i++){
            if(check(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
