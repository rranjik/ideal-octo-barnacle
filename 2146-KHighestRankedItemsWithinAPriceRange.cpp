class Solution {
public:
    struct item{
        int d;
        int r;
        int c;
        int p;
        item(int _d, int _r, int _c, int _p):d(_d), r(_r), c(_c), p(_p){}
        bool operator<(const item& i) const {
            if(d!=i.d) return d<i.d;
            if(p!=i.p) return p<i.p;
            if(r!=i.r) return r<i.r;
            return c<i.c;
        }
        bool operator>(const item& i) const {
            if(d!=i.d) return d>i.d;
            if(p!=i.p) return p>i.p;
            if(r!=i.r) return r>i.r;
            return c>i.c;
        }
    };
    int low;
    int hi;
    struct node{
        int r; int c; int d;
        node(int _r, int _c, int _d):r(_r), c(_c), d(_d){}
    };
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        queue<node> q;
        q.push({start[0], start[1], 0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> v = vector<vector<bool>>(m, vector<bool>(n));
        v[start[0]][start[1]] = true;
        vector<item> items;
        vector<vector<int>> dir = {
            {1,0},
            {0,1},
            {-1, 0},
            {0, -1}
        };
        low = pricing[0];
        hi = pricing[1];
        priority_queue<item, vector<item>, greater<item>> pq;
        //largest distance
        int ld = 0;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            auto r = f.r;
            auto c = f.c;
            auto d = f.d;
            auto p = grid[r][c];
            if(p!=1&&low<=p&&hi>=p){
                items.push_back({d, r, c, p});
                //pq.push({d, r, c, p});
                ld = d;
            }
            for(const auto di : dir){
                int rr = di[0]+r;
                int cc = di[1]+c;
                if(0<=rr&&rr<m&&0<=cc&&cc<n&&grid[rr][cc]!=0&&!v[rr][cc]){
                    q.push({rr, cc, d+1});
                    v[rr][cc] = true;
                }
            }
            //if this item is farther than the last item 
            //that went in the queue and the size of queue
            //is more than k, we have enough elements 
            //to choose from
            if(items.size()>=k&&d>ld) break;
        }            
        vector<vector<int>> res;
        sort(items.begin(), items.end());
        for(int i = 0; i<k&&i<items.size(); i++){
            res.push_back({items[i].r, items[i].c});
        }
        return res;
    }
};
