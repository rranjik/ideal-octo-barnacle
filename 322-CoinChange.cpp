class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0){
            return 0;
        }
        vector<int> t(amount+1, numeric_limits<int>::max()-1);
        t[0] = 0;
        for(const auto& c : coins){
            for(int i = c; i<=amount; i+=1){
                if(t[i]>t[i-c]+1){
                    t[i]=t[i-c]+1;
                }
            }
        }
        return (t[amount]==numeric_limits<int>::max()-1)?-1:t[amount];
    }
};
