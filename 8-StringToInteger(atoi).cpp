class Solution {
public:
    unordered_set<char> v = {'-', '+', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    unordered_set<char> vn = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int mystoi(string s, int sig){
        if(s.length()==0){
            cout<<"mystoi has an empty string"<<endl;
            return 0;
        }
        cout<<"mystoi received "<<s<<" sig = "<<sig<<endl;
        int start = 0;
        while(start<s.length()&&s[start]=='0'){
            start++;
        }
        if(start==s.length()){
            cout<<"just 0's "<<endl;
            return 0;
        }else {
            s = s.substr(start, string::npos);
            cout<<"after trmming leading zeros "<<s<<endl;
        }
        long pow = 1;
        long res = 0;
        int i = s.length()-1;
        while(pow<=numeric_limits<int>::max()&&res<=numeric_limits<int>::max()&&i>=0){
            if(vn.find(s[i])==vn.end()){
                if(s[i]==' '){
                    cout<<"space found return 0"<<endl;
                    return 0;
                }
                else {
                    cout<<"somthing else found breakl"<<endl;
                    break;
                }
            }
            res += ((s[i]-'0')*pow);
            pow*=10;
            i--;
        }
        if(res>numeric_limits<int>::max()){
            cout<<"potential overflow "<<res<<endl;
            if(sig){
                cout<<"+ve overfow return a max"<<endl;
                return numeric_limits<int>::max();
            }else {
                if(res==(numeric_limits<int>::max()+1l)){
                    cout<<"least neg number "<<endl;
                    return numeric_limits<int>::min();
                }else {
                    cout<<"smaller than least neg number "<<endl;
                    return numeric_limits<int>::min();
                    //return 0;
                }
            }
            cout<<"overflow "<<s<<endl;
            cout<<"overflow res "<<res<<endl;
            return 0;
        }else{
            if(i>=0){
                if(sig) return numeric_limits<int>::max();
                else return numeric_limits<int>::min();
            }
            cout<<"all is well "<<res<<endl;
            if(sig){
                return res;
            }else{
                return res*-1;
            }
            return 0;
        }
        return 0;
        
    }
    
    int func(string s){
        int i = 0;
        int number_of_spaces = 0;
        int number_non_spaces = 0;
        while(i<s.length()&&v.find(s[i])==v.end()){
            if(s[i]!=' ') {
                cout<<"non space found "<<endl;
                return 0;
            }
            if(s[i]==' ') number_of_spaces++;
            else number_non_spaces++;
            if(number_of_spaces>1&&number_non_spaces>1){
                cout<<"number of spaces and ns more than 1 = "<<
                    number_of_spaces<<" "<<number_non_spaces<<endl;
                return 0;
            }
            if(number_non_spaces>1) {
                cout<<"number of non spaces more than 1 = "<<number_non_spaces<<endl;
                return 0;
            }
            i++;
        }
        if(i==s.length()){
            cout<<"invalid "<<s<<endl;
            return 0;
        }
        auto vs = s.substr(i, string::npos);
        i=0;
        cout<<"valid string start  = "<<vs<<endl;
        bool signexists = false;
        int sign = 1;
        if((vs[i]=='-')||(vs[i]=='+')){
            signexists = true;
            if(vs[i]=='-') sign = 0;
            cout<<"sign exists "<<vs[i]<<endl;
            vs = vs.substr(1, string::npos);
            cout<<"new valid string start  = "<<vs<<endl;
        }
        int ns = 0;
        cout<<"before ns extract loop "<<ns<<" vs.length() = "<<vs.length()<<endl;
        while((ns<vs.length())&&(ns<10)&&(vn.find(vs[ns])!=vn.end())){
            //cout<<"incrementing ns "<<ns<<endl;
            ns++;
        }
        cout<<"number start = "<<ns<<endl;
        if(ns==vs.length()){
            int real_len = vs.length();
            int number = mystoi(vs, sign);
            return number;
        }
        else if(ns==10){
            //10 digits but still has something after that 
            if(ns<vs.length()){
                cout<<"10 digits but still has something after that "<<vs<<endl;
                if(vn.find(vs[ns])!=vn.end()){
                    cout<<"has a number after 10 digits "<<endl;
                    return mystoi(vs, sign);
                    //return 0;
                }else{
                    cout<<"has something else after 10 digits "<<endl;
                    auto extracted = vs.substr(0, 10);
                    return mystoi(extracted, sign);
                    //return 0;
                }
            }else{
                cout<<"exactly 10 "<<vs<<endl;
                return mystoi(vs, sign);
            }
        }
        //non digit found
        else{
           cout<<"non digit found "<<endl;
           //if(vs[ns] == ' '){
               //cout<<"space after digit continue to stoi "<<endl;
               auto newstring_to_stoi = vs.substr(0, ns);
               return mystoi(newstring_to_stoi, sign);
           //}else{
               //cout<<"there is seomething wrong here "<<vs<<endl;
           //}
           
           //cout<<"non digit found "<<endl;
        }
        return 0;
    }
    int myAtoi(string str) {
        //func("12345");
        //func("abcedf");
        //func("104idk");
        //func("---+");
        //func("00203");
        //func("9u20");
        //func("    004i3");
        //func("00    102");
        //func("2174885667856585");
        //func("1111111111");
        //func("0000000000");
        //func("0000000001");
        //func("-2147483648");
        //func("2147483647");
        //func("-2147483648u");
        //func("2147483647l");
        int number = func(str);
        cout<<"parding returned "<<number<<endl;
        return number;
        //return 0;
    }
};
