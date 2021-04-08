class Solution {
public:
    bool valid(int x, int y, const vector<vector<int>>& b){
        vector<bool> seen(9, false);
        for(int i = 0; i<9; i++){
            if(b[x][i]){
                if(seen[b[x][i]-1]) return false;
                seen[b[x][i]-1] = true;
            }
        }
        seen = vector<bool>(9, false);
        for(int i = 0; i<9; i++){
            if(b[i][y]){
                if(seen[b[i][y]-1]) return false;
                seen[b[i][y]-1] = true;
            }
        }
        seen = vector<bool>(9, false);
        auto bx = (x/3)*3; auto by = (y/3)*3;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(b[bx+i][by+j]){
                    if(seen[b[bx+i][by+j]-1]) return false;
                    seen[b[bx+i][by+j]-1] = true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> b(9, vector<int>(9, 0));
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]!='.'){
                    b[i][j] = board[i][j]-'0';
                }
            }
        }
        auto res = true;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(b[i][j]) {
                    auto r = valid(i, j, b);
                    if(!r) cout<<"i = "<<i<<"; j = "<<j<<" is not valid "<<endl;
                    res&=r;
                }
            }
        }
        return res;
    }
};
