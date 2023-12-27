class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string, vector<string>> adjl;
        int n = rec.size();
        
        unordered_set<string> s(sup.begin(), sup.end());
        
        unordered_map<string, int> in;
        for(const auto& r : rec) in[r] = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<ing[i].size(); j++){
                //if you have the supply just forget about
                //it - you have an infinite supply
                if(s.find(ing[i][j])==s.end()){
                    adjl[ing[i][j]].push_back(rec[i]);
                    in[rec[i]]++;
                }
            }
        }
        
        queue<string> q;
        for(const auto& r : in){
            if(r.second==0) 
                q.push(r.first);
        }
        
        vector<string> res;
        while(!q.empty()){
            auto qs = q.size();
            while(qs){
                auto f = q.front(); q.pop();
                res.push_back(f);
                for(const auto& r : adjl[f]){
                    if(--in[r] == 0){
                        q.push(r);
                    }
                }
                qs--;
            }
        }
        return res;
    }
};
