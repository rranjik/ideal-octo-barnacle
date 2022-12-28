class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> t;
        unordered_map<char, int> f;
        map<int, vector<char>> inv;
        for(const auto& c : s) f[c]++;
        for(const auto& it : f){
            inv[it.second].push_back(it.first);
        }
        int n{};
        int res{};
        int prev{};
        for(const auto& it : inv){
            auto cs = it.second;
            auto fr = it.first;
            cout<<"proc fr = "<<fr<<endl;
            for(const auto& c : cs) cout<<c<<" ";cout<<endl;
            t.insert(fr);
            if(t.find(fr-1)==t.end()) n = fr-1;
            cout<<"n = "<<n<<endl;
            if(cs.size()>1){
                for(int i = 0; i<cs.size()-1; i++){
                    res+=(fr-n);
                    if(n) t.insert(n);
                    while(t.find(n)!=t.end()) n--;
                }
            }
        }
        return res;
    }
};
