class Solution {
public:
    string maskemail(string s){
        auto at = s.find('@');
        auto dot = s.find('.');
        auto n1 = s.substr(0, s.find('@'));
        auto n2 = s.substr(at+1, dot-at-1);
        auto n3 = s.substr(dot+1);
        auto f = (n1[0]);
        auto l = (n1[n1.size()-1]);
        if(isalpha(f)) f = tolower(f);
        if(isalpha(l)) l = tolower(l);
        string mn1;
        mn1.push_back(f);
        mn1.push_back('*');
        mn1.push_back('*');
        mn1.push_back('*');
        mn1.push_back('*');
        mn1.push_back('*');
        mn1.push_back(l);
        mn1.push_back('@');
        string mn2;
        for(const auto& c: n2){
            if(isalpha(c)) mn2.push_back(tolower(c));
            else mn2.push_back(c);
        }
        mn2.push_back('.');
        string mn3;
        for(const auto& c: n3){
            if(isalpha(c)) mn3.push_back(tolower(c));
            else mn3.push_back(c);
        }
        return mn1+mn2+mn3;
    }
    string maskphone(string s) {
        vector<int> phno;
        for(int i = 0; i<s.size(); i++){
            if(isdigit(s[i])){
                phno.push_back(s[i]-'0');
            }
        }
        for(const auto& n : phno)cout<<n<<" "; cout<<endl;
        string res{};
        cout<<"res.size() = "<<res.size()<<endl;
        cout<<"phno.size() = "<<phno.size()<<endl;
        if(phno.size()>10){
            res.push_back('+');
            auto cc = phno.size()-10;
            for(int i = 0; i<cc; i++){
                res.push_back('*');
            }
            res.push_back('-');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('-');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('-');   
            string last4;
            for(int i = phno.size()-1, j = 0; j<4; i--, j++){
                last4.push_back(static_cast<char>('0'+phno[i]));
            }
            reverse(last4.begin(), last4.end());
            cout<<"kast4 = "<<last4<<endl;
            res=res+last4;
        }
        else{
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('-');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('*');   
            res.push_back('-');   
            string last4;
            for(int i = phno.size()-1, j = 0; j<4; i--, j++){
                last4.push_back(static_cast<char>('0'+phno[i]));
            }
            reverse(last4.begin(), last4.end());
            res+=last4;
        }
        return res;
    }
    string maskPII(string S) {
        if(S.find('@')!=string::npos){
            return maskemail(S);
        }else {
            return maskphone(S);
        }
    }
};
