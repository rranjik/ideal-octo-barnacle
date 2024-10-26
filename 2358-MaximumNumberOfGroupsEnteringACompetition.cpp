class Solution {
public:
    int maximumGroups(vector<int>& g) {
        sort(g.begin(), g.end());
        int lg = 0;
        int ls = 0;
        int cs = 0;
        int cg = 0;
        int res = 0;
        for(const auto& m : g){
            cg++;
            cs+=m;
            if(cg>lg&&cs>ls){
                lg = cg; ls = cs;
                cg = 0; cs = 0;
                res++;
            }
        }
        return res;
    }
};
