class Solution {
public:
    int digitsum(int n){
        int res{};
        while(n){
            res+=(n%10);
            n/=10;
        }
        return res;
    }
    int countLargestGroup(int n) {
        map<int, int> f;
        int largestgroup{};
        for(int i = 1; i<=n; i++){
            int thisdigitsum = digitsum(i);
            f[thisdigitsum]++;
            largestgroup = max(largestgroup, f[thisdigitsum]);
        }
        int res{};
        for(const auto& it : f){
            if(it.second==largestgroup) res++;
        }
        return res;
    }
};
