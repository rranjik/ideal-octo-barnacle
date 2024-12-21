class Solution {
public:
    int countAsterisks(string s) {
        bool inside = false;
        int res = 0;
        for(const auto& c : s){
            if(c=='|'&&inside){
                inside = false;
            }else if(c=='|'&&!inside){
                inside = true;
            }
            if(c=='*'&&!inside){
                res++;
            }
        }
        return res;
    }
};
