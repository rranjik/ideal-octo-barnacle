class Solution {
public:
    string thousandSeparator(int n) {
        auto s = to_string(n);
        int g = 0;
        string res;
        for(int j = s.size()-1; j>=0; j--){
            cout<<"j = "<<j<<" s[j] = "<<s[j]<<" res = "<<res<<endl;
            g++;
            res.push_back(s[j]);
            if(g==3&&(j)){
                res.push_back('.');
                g = 0;
            }
            cout<<"res = "<<res<<" g = "<<g<<endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
