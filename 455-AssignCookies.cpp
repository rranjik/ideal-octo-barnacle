class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res{};
        for(int i = 0, j = 0; i<g.size()&&j<s.size();){
            if(g[i]<=s[j]){
                i++;
                j++;
                res++;
            }else{
                j++;
            }
        }
        return res;
    }
};
