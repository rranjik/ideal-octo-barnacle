class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for(auto c : str){
            if((c>=65)&&(c<=90)){
                c+=32;
            }
            res+=c;
        }
        return res;
    }
};
