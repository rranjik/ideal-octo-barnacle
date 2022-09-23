class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int c{};
        for(const auto& a : arr){
            if(a%2){
                c++;
                if(c>=3) return true;
            }else c = 0;
        }
        return false;
    }
};
