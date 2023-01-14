class Solution {
public:
    string removeStars(string s) {
        //put chars into a stack
        //pop if you see a *
        string res;
        for(int i = 0; i<s.size(); i++){
            if(s[i]!='*') res+=s[i];
            else res.pop_back();
        }
        return res;
    }
};
