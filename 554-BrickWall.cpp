struct brick{
    int i;
    int j;
    int l;
    brick(int _i, int _j, int _l):i(_i),j(_j),l(_l){}
};
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        auto cmp = [](const brick& b1, const brick& b2){
            return b1.l>b2.l;
        };
        priority_queue<brick, vector<brick>, decltype(cmp)> q(cmp);
        vector<int> edges(wall.size());
        for(int i = 0; i<wall.size(); i++){
            q.push(brick(i, 0, wall[i][0]));
            //edges[i] = wall[i][0];
        }
        int res = numeric_limits<int>::max();
        while(!q.empty()){
            bool e = false;
            vector<brick> bs;
            auto b1 = q.top();
            q.pop();
            bs.push_back(b1);
            if(b1.j+1<wall[b1.i].size()) e = true;
            while(!q.empty()&&q.top().l==b1.l){
                auto b2 = q.top();
                if(b2.j+1<wall[b2.i].size()) e = true;
                bs.push_back(b2);
                q.pop();
            }
            if(e)
            res = min(res, (int)q.size());
            for(const auto& b : bs){
                if(b.j+1<wall[b.i].size()){
                    q.push(brick(b.i, b.j+1, b.l+wall[b.i][b.j+1]));
                    //edges[b.i] = edges[b.i]+wall[b.i][b.j+1];
                }
            }
        }
        return res==numeric_limits<int>::max()?wall.size():res;
    }
};
