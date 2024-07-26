class Solution {
public:
    int parse(string t){
        return stoi(t.substr(0, 2))*60+stoi(t.substr(3));
    }
    vector<string> alertNames(vector<string>& kn, vector<string>& kt) {
        unordered_map<string, set<int>> f;
        unordered_map<string, set<int>> t;
        set<string> res;
        for(int i = 0; i<kn.size(); i++){
            auto m = parse(kt[i]);
            auto n = kn[i];
            t[n].insert(m);
        }
        for(const auto& [n, tt]: t){
            for(const auto& m : tt){
                cout<<n<<" enters at "<<m<<endl;
                f[n].insert(m);
                if(distance(f[n].lower_bound(m-60), f[n].find(m))>=2) 
                    res.insert(n);
            }
        }
        return {res.begin(), res.end()};
    }
};
