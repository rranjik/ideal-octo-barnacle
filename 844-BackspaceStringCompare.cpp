class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto sp = 0;
        auto tp = 0;
        int i = 0;
        while(i<s.length()){
            cout<<"i = "<<i<<"; sp = "<<sp<<"; s = "<<s<<endl;
            if(s[i]=='#'){
                sp = sp?--sp:sp;
            }else{
                s[sp] = s[i];
                sp++;
            }
            i++;
        }
        i = 0;
        while(i<t.length()){
            cout<<"i = "<<i<<"; tp = "<<tp<<"; t = "<<t<<endl;
            if(t[i]=='#'){
                tp = tp?--tp:tp;
            }else{
                t[tp] = t[i];
                tp++;
            }
            i++;
        }
        return s.substr(0, sp) == t.substr(0, tp);
    }
};
