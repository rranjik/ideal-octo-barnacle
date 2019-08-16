class Solution {
public:
    using coor = pair<int, int>; 
    bool isValid(coor c, const vector<string>& b){
        int i = 0;
        while(i<c.first){
            if(b[i][c.second]=='Q')return false;
            i++;
        }
        i = c.first-1;
        int j = c.second-1;
        while(i>=0&&j>=0){
            if(b[i][j]=='Q') return false;
            i--;
            j--;
        }
        i = c.first-1;
        j = c.second+1;
        while(i>=0&&j<b.size()){
            if(b[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void place(int r, vector<string>& board, vector<vector<string>>& res){
        int n = board.size();
        if(r==n){
            res.push_back(board);
            return;
        }
        else{
            for(int i = 0; i<n; i++){
                if(isValid(coor(r,i), board)){
                    board[r][i]='Q';
                    place(r+1, board, res);
                    board[r][i]='.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> b(n, string(n, '.'));
        place(0, b, res);
        return res;
    }
};
