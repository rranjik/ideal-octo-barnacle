class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int planted = 0;
        int i = 0;
        while(i<f.size()){
            if(!f[i]&&(i-1<0||!f[i-1])&&(i+1>=f.size()||!f[i+1])) {
                f[i] = 1;
                planted++;
            }
            i++;
        }
        if(planted>=n) return true;
        return false;
    }
};
