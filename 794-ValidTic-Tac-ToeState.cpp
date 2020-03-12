class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xc = 0;
        int oc = 0;
        for(const auto& row : board){
            for(const auto& c :row){
                if(c=='X') xc++;
                if(c=='O') oc++;
            }
        }
        if(xc!=oc&&xc-1!=oc)return false;
        if(win(board, 'X')&&xc-1!=oc) return false;
        if(win(board, 'O')&xc!=oc) return false;
        return true;
    }
    
    bool win(vector<string>& board, char p){
        for(int i = 0; i<board.size(); i++){
            if(board[i][0]==p&&board[i][1]==p&&board[i][2]==p) return true;
            if(board[0][i]==p&&board[1][i]==p&&board[2][i]==p) return true;
        }
        if(board[0][0]==p&&board[1][1]==p&&board[2][2]==p)
            return true;
        if(board[0][2]==p&&board[1][1]==p&&board[2][0]==p)
            return true;
        return false;
    }
};
