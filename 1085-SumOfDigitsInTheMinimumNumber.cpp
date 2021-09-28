class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int mini = numeric_limits<int>::max();
        for(const auto& n : A){
            mini = min(mini, n);
        }
        int sum= 0;
        while(mini){
            int d = mini%10;
            sum+=d;
            mini/=10;
        }
        if(sum%2) return 0;
        else return 1;
    }
};
