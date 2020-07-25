class Solution {
public:
    char const x = 'X';
    char const o = 'O';
    int n; int m;
    //visited
    vector<vector<bool>> vstd;
    //component numbers
    vector<vector<int>> cn;
    vector<vector<char>> b;
    bool dfs(int i, int j, const int& c){
        if(i>=n||i<0||j>=m||j<0) return true;
        vstd[i][j] = true;
        cn[i][j] = c;
        bool left = false; bool right = false; bool up = false; 
        bool down = false;
        bool amIborder = false;
        if(i-1>=0&&!vstd[i-1][j]&&b[i-1][j]==o)up = dfs(i-1, j, c);
        if(j-1>=0&&!vstd[i][j-1]&&b[i][j-1]==o)left = dfs(i, j-1, c);
        if(i+1<n&&!vstd[i+1][j]&&b[i+1][j]==o)down = dfs(i+1, j, c);
        if(j+1<m&&!vstd[i][j+1]&&b[i][j+1]==o)right = dfs(i, j+1, c);
        if(i==0||i==n-1||j==0||j==m-1){
            amIborder = true;
        }else amIborder = false;
        return amIborder||left||right||up||down;
    }
    void capture(vector<vector<char>>& board, int c){
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(cn[i][j]==c){
                    board[i][j] = 'X';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(!board.size())return;
        n = board.size();
        m = board[0].size();
        b = board;
        vstd = vector<vector<bool>>(n, vector<bool>(m, false));
        cn = vector<vector<int>>(n, vector<int>(m, -1));
        int cc = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(board[i][j] == o&&!vstd[i][j]){
                    cc++;
                    if(!dfs(i, j, cc)){
                       capture(board, cc);
                    }
                }
            }
        }
    }
};
