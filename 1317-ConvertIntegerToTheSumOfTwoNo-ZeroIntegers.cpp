class Solution {
public:
    bool isnz(int n){
        while(n){
            int d = n%10;
            if(!d)return false;
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i<n; i++){
            int a = i;
            int b = (n-i);
            if(isnz(a)&&isnz(n-i)){
                vector<int> res;
                res.push_back(a);  
                res.push_back(b);  
                return res;
            }
        }
        return vector<int>();
    }
};
