class Solution {
public:
    string rD(string s, int k, bool& rem) {
        string r;
        for(int i = 0; i<s.length();){
            string ss = s.substr(i, k);
            //cout<<"i = "<<i<<"; "<<ss<<endl;
            if(ss.length()==k){
                char x = ss[0];
                bool skip = true;
                for(const auto& c: ss){
                    //cout<<"x = "<<x<<"; c = "<<c<<endl;
                    if(x!=c){
                        skip= false;
                        break;
                    }
                }
                if(skip){
                    //cout<<"found a match at "<< i<<endl;
                    i+=k;
                    rem = true;
                }
                else {
                    r+=(s[i]);
                    i++;
                }
            }
            else{
                r+=(s[i]);
                i++;
            }
        }
        //cout<<r<<endl;
        return r;
    }
    string removeDuplicates(string s, int k) {
        bool rem = false;
        while(!rem){
            auto r = rD(s, k , rem);
            if(!rem){
                return r;
            }
            else{
                s = r;
                rem = false;
            }
        }
        return s;
    }
};
