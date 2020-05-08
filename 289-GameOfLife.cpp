class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int tl=0,t=0,tr=0,l=0,r=0,bl=0,b=0,br=0;
                if((i-1>=0)&&(j-1>=0)) tl = (board[i-1][j-1])&1;
                if((i-1>=0)) t = (board[i-1][j])&1;
                if((i-1>=0)&&(j+1<m)) tr = (board[i-1][j+1])&1;
                if((j-1>=0)) l = (board[i][j-1])&1;
                if((j+1<m)) r = (board[i][j+1])&1;
                if((i+1<n)&&(j-1>=0)) bl = (board[i+1][j-1])&1;
                if((i+1<n)) b = (board[i+1][j])&1;
                if((i+1<n)&&(j+1<m)) br = (board[i+1][j+1])&1;
                int count = tl+t+tr+l+r+bl+b+br;
                if((board[i][j])&1){
                    if(count<2) {}//don't care will have 01 anyway
                    if(count ==2||count==3){board[i][j]=3;}
                    if(count>3) {}//don't care will have 01 anyway
                }else {
                    if(count==3) board[i][j]=2;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                board[i][j]>>=1;
            }
        }
        return;
    }
};
