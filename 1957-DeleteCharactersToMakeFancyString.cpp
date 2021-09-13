class Solution {
public:
    string makeFancyString(string s) {
        s.push_back('*');
        int cnt = 1;
        string res;
        for(int i = 1; i<s.size(); i++){
            if(s[i]==s[i-1]) {
                cnt++;
            }else{
                if(cnt>2){
                    res.push_back(s[i-1]);
                    res.push_back(s[i-1]);
                    cnt = 1;
                }else{
                    if(cnt==2){
                        res.push_back(s[i-1]);
                        res.push_back(s[i-1]);
                    }else{
                        res.push_back(s[i-1]);
                    }
                    cnt = 1;
                }
            }
        }
        return res;
    }
};
