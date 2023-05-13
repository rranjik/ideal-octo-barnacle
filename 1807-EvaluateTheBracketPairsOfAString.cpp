class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        int last_pos = 0;
        int opos = -1;
        vector<string> keys;
        unordered_map<string, string> kn;
        for(const auto& k : know){
            kn[k[0]] = k[1];
        }
        while((opos = s.find('(', last_pos))!=string::npos){
            auto cpos = s.find(')', opos+1);
            last_pos = cpos;
            auto k = s.substr(opos+1, cpos-opos-1);
            keys.push_back(k);
            //cout<<k<<endl;
        }
        bool fo = false;
        bool fc = false;
        string nk;
        string res;
        int ki = 0;
        for(int i = 0; i<s.size(); i++){
            if(!fo&&s[i]!='('){
                nk+=string(1, s[i]);
                fo = false;
            }else if(s[i]=='('){
                //cout<<nk<<endl;
                res+=nk;
                if(kn.find(keys[ki])!=kn.end()){
                    res+=kn[keys[ki]];
                }else{
                    res+="?";
                }
                ki++;
                nk= "";
                fo = true;
            }else if(s[i]==')'){
                fo = false;
            }
        }
        //cout<<nk<<endl;
        res+=nk;
        return res;
    }
};
