class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        vector<int> res;
        res.push_back(10);
        for(int i=1; i<=10; i++){
            int r = 9;
            for(int j = i, m=9; j>=1; j--,m--){
                r*=m;
            }
            int p = res[res.size()-1];
            res.push_back(r+p);
        }
        if(n>=10)
            return res[10];
        else return res[n-1];
        for(const auto& n : res)
            cout<<n<<" ";
        return 0;
    }
};
