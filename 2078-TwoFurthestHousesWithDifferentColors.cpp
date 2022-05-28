class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        for(int i = colors.size()-1; i>=0; i--){
            if(colors[i]!=colors[0]) {
                res = i;
                break;
            }
        }
        for(int i = 0; i<colors.size(); i++){
            if(colors[i]!=colors[0]) {
                res = max(res, (int)colors.size()-i-1);
                break;
            }
        }
        return res;
    }
};
