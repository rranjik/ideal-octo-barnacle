class Solution {
public:
    int countHomogenous(string s) {
        auto l = s[0];
        long long n = s.size();
        long long res{};
        long long sl{1};
        int m = 1e9+7;
        for(int i = 1; i<n; i++){
            if(s[i]==s[i-1]){
                sl++;
            }else{
                res += ((sl*(sl+1))/2)%m;
                sl = 1;
            }
        }
        res += ((sl*(sl+1))/2)%m;
        return res;
    }
};
