class Solution {
public:
    int sum(int n){
        int res{};
        while(n){
            res+=(n%10);
            n/=10;
        }
        return res;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> m;
        int res = -1;
        for(int i = lowLimit; i<=highLimit; i++){
            auto n = i;
            auto s = sum(i);
            m[s]++;
            res = max(res, m[s]);
        }
        return res;
    }
};
