class Solution {
public:
    vector<vector<bool>> v;
    vector<vector<char>> b;
    int m;
    int n;
    void dfs(int x, int y){
        if(x<0||y<0||x>=m||y>=n||v[x][y]) return;
        if(b[x][y]=='M') {
            b[x][y] = 'X'; return;
        }
        if(b[x][y]!='E') return;
        cout<<"x = "<<x<<"; y = "<<y<<" started"<<endl;
        v[x][y] = true;
        int numberOfAdjacentMines = 0;
        if(x-1>=0&&y-1>=0&&b[x-1][y-1]=='M') numberOfAdjacentMines++;
        if(x-1>=0&&b[x-1][y]=='M') numberOfAdjacentMines++;
        if(x-1>=0&&y+1<n&&b[x-1][y+1]=='M') numberOfAdjacentMines++;
        if(y-1>=0&&b[x][y-1]=='M') numberOfAdjacentMines++;
        if(y+1<n&&b[x][y+1]=='M') numberOfAdjacentMines++;
        if(x+1<m&&y-1>=0&&b[x+1][y-1]=='M') numberOfAdjacentMines++;
        if(x+1<m&&y>=0&&b[x+1][y]=='M') numberOfAdjacentMines++;
        if(x+1<m&&y+1<n&&b[x+1][y+1]=='M') numberOfAdjacentMines++;
        if(numberOfAdjacentMines){
            b[x][y] = (char)('0'+numberOfAdjacentMines);
        cout<<"x = "<<x<<"; y = "<<y<<" am returns"<<endl;
        }else{
            b[x][y] = 'B';
            dfs(x-1, y-1);
            dfs(x-1, y);
            dfs(x-1, y+1);
            dfs(x, y-1);
            dfs(x, y+1);
            dfs(x+1, y-1);
            dfs(x+1, y);
            dfs(x+1, y+1);
            cout<<"x = "<<x<<"; y = "<<y<<" recursion returns"<<endl;
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, 
                                     vector<int>& click) {
        m = board.size();
        if(!m) return board;
        n = board[0].size();
        
        b = board;
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        
        dfs(click[0], click[1]);
        return b;
    }
};
