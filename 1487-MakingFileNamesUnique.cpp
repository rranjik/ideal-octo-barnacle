class Solution {
public:
    unordered_set<string> taken;
    bool endsInK(const string& s, string& p, int& n){
        if(s[s.length()-1]!=')') return false;
        int open{};
        bool found = false;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i]=='('){
                open = i;
                found = true;
                break;
            }
        }
        auto b = s.substr(open+1);
        b.pop_back();
        try{
            n = stoi(b);
        }catch(...){
            return false;
        }
        p = s.substr(0, open);
        return true;
    }
    unordered_map<string, int> tn;
    unordered_map<string, unordered_set<int>> takenn;
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        for(const auto& n : names){
            if(taken.find(n)==taken.end()){
                string p;
                int num;
                if(endsInK(n, p, num)){
                    takenn[p].insert(num);
                    if(tn.find(p)==tn.end()) tn[p] = 1;
                    while(takenn[p].find(tn[p])!=takenn[p].end()){
                        tn[p]++;
                    }
                }else{
                    int s{};
                    if(tn.find(n)==tn.end()) {
                        tn[n] = 1;
                    }
                    else{
                        while(takenn[n].find(tn[n])!=takenn[n].end()){
                            tn[n]++;
                        }
                    }
                }
                taken.insert(n);
                res.push_back(n);
            }else{
                string r;
                if(tn.find(n)==tn.end()) tn[n] = 1;
                r+=n; r+="("; r+=to_string(tn[n]); r+=")";
                takenn[n].insert(tn[n]);
                while(takenn[n].find(tn[n])!=takenn[n].end()){
                    tn[n]++;
                }
                taken.insert(r);
                res.push_back(r);
            }
        }
        return res;
    }
};
