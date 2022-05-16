class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        if(calories.size()<k) return 0;
        int l = 0;
        int r = 0;
        int rs = 0;
        while(r<k){
            rs += calories[r];
            r++;
        }
        r--;
        int res = 0;
        while(r<calories.size()){
            cout<<"l = "<<l<<" r = "<<r<<" rs = "<<rs<<endl;
            if(rs<lower){
                res--;
            }
            if(rs>upper){
                res++;
            }
            r++;
            if(r<calories.size()){
                rs-=calories[l];
                rs+=calories[r];
                l++;
            }
        }
        return res;
    }
};
