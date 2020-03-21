class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int l, b;
    bool cc(int i, int j){
        visited[i][j] = true;
        auto tl = false;auto t = false;auto tr = false;auto left = false; 
        auto r = false;auto bl = false;auto bot = false;auto br = false; 
        //tl
        //if(i-1>=0&&j-1>=0&&!visited[i-1][j-1]&&!grid[i-1][j-1]) tl = cc(i-1, j-1);
        //t
        if(i-1>=0&&!visited[i-1][j]&&!grid[i-1][j]) t = cc(i-1, j);
        //tr
        //if(i-1>=0&&j+1<b&&!visited[i-1][j+1]&&!grid[i-1][j+1]) tr = cc(i-1, j+1);
        //left
        if(j-1>=0&&!visited[i][j-1]&&!grid[i][j-1]) left = cc(i, j-1);
        //r
        if(j+1<b&&!visited[i][j+1]&&!grid[i][j+1]) r = cc(i, j+1);
        //bl
        //if(i+1<l&&j-1>=0&&!visited[i+1][j-1]&&!grid[i+1][j-1]) bl = cc(i+1, j-1);
        //bot
        if(i+1<l&&!visited[i+1][j]&&!grid[i+1][j]) bot = cc(i+1, j);
        //br
        //if(i+1<l&&j+1<b&&!visited[i+1][j+1]&&!grid[i+1][j+1]) br = cc(i+1, j+1);
        auto thiscorner = false;
        if(i==0||i==grid.size()-1||j==0||j==grid[i].size()-1) thiscorner = true;
        auto anycorner = false;
        if(tr||t||tr||left||r||bl||bot||br) anycorner = true;
        return thiscorner||anycorner;
    }
    int closedIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        if(grid.size()==0) return 0;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        l = grid.size(); b = grid[0].size();
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(!visited[i][j]&&!grid[i][j]){
                    if(cc(i, j)){
                        cout<<"cc; "<<"i="<<i<<"; j= "<<j<<" in corner"<<endl;
                    } else {
                        cout<<"cc; "<<"i="<<i<<"; j= "<<j<<" not in corner"<<endl;
                        res+=1;
                    }
                }
            }
        }
        return res;
    }
};
