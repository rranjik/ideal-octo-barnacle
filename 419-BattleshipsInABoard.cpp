class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        if(!m) return 0;
        int n = board[0].size();
        int count = 0;
        for(int x = 0; x<m; x++){
            for(int y = 0; y<n; y++){
                if(x-1>=0&&board[x-1][y]=='X'){
                    continue;
                }
                if(y-1>=0&&board[x][y-1]=='X'){
                    continue;
                }
                if(board[x][y]=='X'){
                    count++;
                    cout<<"x = "<<x<<"; y = "<<y<<"; count = "<<count<<endl;
                }
            }
        }
        return count;
    }
};
