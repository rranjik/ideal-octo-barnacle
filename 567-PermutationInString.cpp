class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0);
        vector<int> f(26, 0);
        int len = s1.length();
        for(const auto& c : s1) {
            f1[c-'a']++;
        }
        f = f1;
        int tomatch = len;
        int i = 0;
        for(int j = 0; j<s2.length(); j++){
            cout<<"i = "<<i<<"; j = "<<j<<endl;
            if(f1[s2[j]-'a']){
                f1[s2[j]-'a']--;
                tomatch--;
                if(!tomatch) return true;
            }else{
                if(f[s2[j]-'a']){
                    char v = s2[j];
                    while(s2[i]!=v){
                        tomatch++;
                        f1[s2[i]-'a']++;
                        i++;
                    }
                    i++;
                }else{
                    i = j+1;
                    f1 = f;
                    tomatch = len;
                }
            }
        }
        return false;
    }
};
