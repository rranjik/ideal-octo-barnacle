struct Node{
    int x; int y; int d;
    Node(int _x, int _y, int _d):x(_x), y(_y), d(_d){}
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        deque<Node> q;
        q.push_back({0, 0, 0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        v[0][0] = true;
        while(!q.empty()){
            auto node = q.front();
            //cout<<"x = "<<node.x<<" y = "<<node.y<<" d = "<<node.d<<endl;
            q.pop_front();
            v[node.x][node.y]=true;
            if(node.x==m-1&&node.y==n-1) return node.d;
            for(auto& d : dirs){
                auto xx = node.x+d.first;
                auto yy = node.y+d.second;
                auto cost = 0;
                if(xx>=0&&yy>=0&&xx<m&&yy<n&&!v[xx][yy]){
                    if(grid[node.x][node.y]==1&&d.first==0&&d.second==1)cost = 0;
                    else if(grid[node.x][node.y]==2&&d.first==0&&d.second==-1)cost = 0;
                    else if(grid[node.x][node.y]==3&&d.first==1&&d.second==0)cost = 0;
                    else if(grid[node.x][node.y]==4&&d.first==-1&&d.second==0)cost = 0;
                    else cost = 1;
                    if(cost == 0) q.push_front({xx, yy, node.d});
                    else q.push_back({xx, yy, node.d+1});
                }
            }
        }
        return 0;
    }
};
