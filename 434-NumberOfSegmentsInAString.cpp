class Solution {
public:
    int countSegments(string s) {
        //if(!s.length()) return 0;
        //bool found = false;
        //for(const auto& c : s) {if(c!=' ') {found = true; break;}}
        //if(!found) return 0;
        stringstream ss(s);
        int res{};
        while(!ss.eof()){
            string e;
            ss>>e;
            if(e.length())
            res++;
        }
        return res;
    }
};
