class Solution {
public:
    vector<string> sb(int n){
        if(!n){
            return vector<string>();
        }
        if(n==1){
            return vector<string>{"0", "1","8"};
        }
        if(n==2){
            return vector<string>{"11", "69", "88", "96", "00"};
        }
        map<char, char> strobs = {
            {'0', '0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        vector<string> res;
        for(auto it: strobs){
            string s;
            s+=(it.first);
            auto n2 = sb(n-2);
            for(const auto nn : n2){
                auto nnn = s+nn;
                nnn+=it.second;
                res.push_back(nnn);
            }
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        auto r = sb(n);
        if(n==1) return r;
        else{
            r.erase(remove_if(begin(r), end(r), [](const string& s){return s[0]=='0';}), end(r));
        }
        return r;
    }
};
