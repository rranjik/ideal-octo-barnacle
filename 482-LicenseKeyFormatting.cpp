class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string wodash;
        for(int i = 0; i<s.length(); i++){
            if(s[i]!='-')
                wodash+=toupper(s[i]);
        }
        cout<<wodash<<endl;
        string res;
        int u = wodash.length()%k;
        cout<<"u = "<<u<<endl;
        for(int i = 0; i<u; i++){
            res+=wodash[i];
        }
        if(u) res+='-';
        for(int i = u, j = 0; i<wodash.length(); i++, j++){
            res+=wodash[i];
            if((j+1)%k==0)
                res+='-';
        }
        if(res[res.length()-1]=='-')res.pop_back();
        return res;
    }
};
