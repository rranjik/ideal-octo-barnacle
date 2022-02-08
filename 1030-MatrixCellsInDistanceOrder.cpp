class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<pair<int, int>> q;
        q.push({r0, c0});
        unordered_map<int, unordered_set<int>> seen;
        vector<pair<int, int>> dirs = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
        vector<vector<int>> res;
        seen[r0].insert(c0);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i<len; i++){
                auto f = q.front();
                q.pop();
                res.push_back({f.first, f.second});
                for(const auto& d : dirs){
                    if(f.first+d.first>=0
                      &&f.first+d.first<R
                      &&f.second+d.second>=0
                      &&f.second+d.second<C
                      &&(seen.find(f.first+d.first)==seen.end()||
                        seen[f.first+d.first].find(f.second+d.second)
                         ==seen[f.first+d.first].end())){
                        q.push({f.first+d.first, f.second+d.second});
                        seen[f.first+d.first].insert(f.second+d.second);
                    }
                }
            }
        }
        return res;
    }
};
