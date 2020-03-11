class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n);
        cols = vector<int>(n);
        diag = 0;
        rev_diag = 0;
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int to_add = player == 1?1:-1;
        rows[row]+=to_add;
        cols[col]+=to_add;
        diag+=((row==col)?to_add:0);
        rev_diag+=((row==N-col-1)?to_add:0);
        return (abs(rows[row])==N||abs(cols[col])==N||abs(diag)==N||abs(rev_diag)==N)?player:0;
    }
    vector<int> rows, cols;
    int diag, rev_diag, N;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
