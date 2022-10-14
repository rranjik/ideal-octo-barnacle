class Solution {
public:
    string modifyString(string s) {
        string res;
        for(int i = 0; i<s.length(); i++){
            auto c = s[i];
            if(c=='?'){
                char prev = '?';
                if(i-1>=0) prev = res.back();
                char next = '?';
                if(i+1<s.length()) next = s[i+1];
                if(prev!='?'&&next!='?'){
                    auto n = 'a';
                    while(n==next||n==prev) n++;
                    res.push_back(n);
                }else if(next == '?'&&prev!='?'){
                    res.push_back(static_cast<char>(prev)=='z'?'a':static_cast<char>(prev+1));
                }else if(prev == '?'&&next!='?'){
                    res.push_back(static_cast<char>(next)=='z'?'a':static_cast<char>(next+1));
                }else{
                    res.push_back('a');
                }
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
};
