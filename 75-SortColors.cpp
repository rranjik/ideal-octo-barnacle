class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;
        for(const auto& n :nums){
            switch(n){
                case 0: r++; break;
                case 1: w++; break;
                case 2: b++; break;
            }
        }
        int i = 0;
        while(r){
            nums[i] = 0;
            r--;
            i++;
        }
        while(w){
            nums[i] = 1;
            w--;
            i++;
        }
        while(b){
            nums[i] = 2;
            b--;
            i++;
        }
    }
};
