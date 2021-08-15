class Solution {
public:
    int maxScore(string s) {
        vector<int> z(s.size());
        vector<int> w(s.size());
        auto zaccum = 0;
        for(int i = 0; i<s.size(); i++){
            zaccum+=(s[i]=='0'?1:0);
            z[i] = zaccum;
        }
        
        auto waccum = 0;
        for(int i = s.size()-1; i>=0; i--){
            waccum+=(s[i]=='1'?1:0);
            w[i] = waccum;
        }
        cout<<"z: ";
        for(int i = 0; i<s.size(); i++) cout<<z[i]<<" ";
        cout<<endl;
        
        cout<<"w: ";
        for(int i = 0; i<s.size(); i++) cout<<w[i]<<" ";
        cout<<endl;
       
        int res = numeric_limits<int>::min();
        for(int i = 0; i<s.size()-1; i++){
            res = max(res, z[i]+w[i+1]);
        }
        return res;
    }
};
