class Solution {
public:
    int gcd(int a, int b){
        if(a>b) return gcd(b, a);
        if(a==0) return b;
        return gcd(b%a, a);
    }
    int findGCD(vector<int>& nums) {
        int a = *(min_element(begin(nums), end(nums)));
        int b = *(max_element(begin(nums), end(nums)));
        return gcd(a, b);
    }
};
