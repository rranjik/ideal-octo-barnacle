class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto orig = heights;
        sort(heights.begin(), heights.end());
        int res = 0;
        for(int i = 0; i<heights.size(); i++){
            if(heights[i]!=orig[i]) res++;
        }
        return res;
    }
};
