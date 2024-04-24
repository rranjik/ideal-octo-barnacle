class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3) return {};
        long long x = (num+3)/3;
        return {x-2, x-1, x};
    }
};
