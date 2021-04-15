class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 0; i<s.length()/2; i++){
            if(!(s.length()%(i+1))){
                auto sub = s.substr(0, i+1);
                string rep;
                for(int j = 0; j<s.length()/(i+1); j++) rep+=sub;
                if(rep==s) return true;
            }
        }
        return false;
    }
};
