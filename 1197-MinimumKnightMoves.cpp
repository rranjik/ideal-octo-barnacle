class Solution {
public:
    
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        using pii = pair<int, int>;
        set<pair<int, int>> steps = {{2,1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
                                     {1, -2}, {2, -1}};
        unordered_map<int, unordered_map<int, bool>> v;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int res = 0;
        while(!q.empty()){
            //cout<<"res = "<<res<<endl;
            auto len = q.size();
            for(int i = 0; i<len; i++){
                auto c = q.front();
                q.pop();
                //cout<<"x = "<<c.first<<"; y = "<<c.second<<endl;
                if(c.first==x&&c.second==y){
                    return res;
                }
                for(const auto& s : steps){
                    auto nx = c.first+s.first;
                    auto ny = c.second+s.second;
                    if(!v[nx][ny]&&nx>=-2&&ny>=-2){
                        v[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            res++;
        }
        return res;
    }
};
