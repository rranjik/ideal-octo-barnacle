class Solution {
public:
    int minFlips(string target) {
        int nflips = 0;
        auto res= 0;
        for(int i = 0; i<target.size(); i++){
            if(nflips%2){
                auto here = 1;
                auto req = target[i]=='0'?0:1;
                if(req!=here) {nflips++; res++; }
            }else{
                auto here = 0;
                auto req = target[i]=='0'?0:1;
                if(req!=here) {nflips++; res++;}
            }
        }
        return res;
    }
};
