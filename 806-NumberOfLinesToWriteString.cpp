class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int cw = 100;
        int lines = 1;
        int ll{};
        for(const auto& c : S){
            auto woc = widths[c-'a'];
            if(cw-woc>=0){
                cw-=woc;
                ll = 100-cw;
            }else {
                lines++;
                cw = 100;
                cw-=woc;
                ll = 100-cw;
            }
        }
        return {lines, ll};
    }
};
