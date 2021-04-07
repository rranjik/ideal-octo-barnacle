class Solution {
public:
    vector<bool> find(int x, int y, const vector<vector<int>>& b){
        vector<bool> res(9, false);
        for(int i = 0; i<9; i++){
            if(b[x][i]) res[b[x][i]-1] = 1;
        }
        for(int i = 0; i<9; i++){
            if(b[i][y]) res[b[i][y]-1] = 1;
        }
        auto bx = (x/3)*3; auto by = (y/3)*3;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(b[bx+i][by+j]) res[b[bx+i][by+j]-1] = 1;
            }
        }
        return res;
    }
    vector<vector<int>> res;
    void dfs(int x, int y, vector<vector<int>>& b){
        if(x>=9||y>=9) {
            res = b;
            cout<<"almost there "<<endl;
            for(const auto& r : b){
                for(const auto& n : r){
                    cout<<n<<" ";
                }
                cout<<endl;
            }
            return;
        }
        if(!b[x][y]){
            auto c = find(x, y, b);
            for(int i = 0; i<9; i++){
                if(!c[i]){
                    b[x][y] = i+1;
                    if(y+1>=9) dfs(x+1, 0, b);
                    else dfs(x, y+1, b);
                    b[x][y] = 0;
                }
            }
        }else {
            if(y+1>=9) dfs(x+1, 0, b);
            else dfs(x, y+1, b);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> b(9, vector<int>(9));
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]!='.') b[i][j] = board[i][j]-'0';
                else b[i][j] = 0;
            }
        }
        dfs(0, 0, b);
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                board[i][j] = '0'+res[i][j];
            }
        }
    }
};
