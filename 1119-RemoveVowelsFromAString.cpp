class Solution {
public:
    string removeVowels(string S) {
        string res;
        for(const auto& c: S){
            if((c!='a')&&(c!='e')&&(c!='i')&&(c!='o')&&(c!='u'))
                res+=c;
        }
        return res;
    }
};
