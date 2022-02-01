class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(!num) return false;
        if(num==1) return false;
        int sum{};
        for(int i = 1; i*i<=num; i++){
            if(num%i==0){
                sum+=i;
                auto other = num/i;
                if(other!=num)
                sum+=other;
            }
        }
        return sum==num;
    }
};
