class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = -1;
        int y = -1;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j]=='R') {
                    x = i;
                    y = j;
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        cout<<"x = "<<x<<"; y = "<<y<<endl;
        for(int i = 0; i<4; i++){
            auto xx=x;
            auto yy=y;
            xx+=dirs[i][0];
            yy+=dirs[i][1];
            while(xx/*+dirs[i][0]*/>=0&&
                  xx/*+dirs[i][0]*/<=7&&
                  yy/*+dirs[i][1]*/<=7&&
                  yy/*+dirs[i][1]*/>=0&&
                  board[xx/*+dirs[i][0]*/][yy/*+dirs[i][1]*/]=='.'){
                xx+=dirs[i][0];
                yy+=dirs[i][1];
                cout<<"xx+ "<<xx<<"; yy+ "<<yy<<endl;
            }
            cout<<"out xx+ "<<xx+dirs[i][0]<<"; yy+ "<<yy+dirs[i][1]<<endl;
            if(xx>=0&&xx<=7&&yy<=7&&yy>=0) {
                //xx+=dirs[i][0];
                //yy+=dirs[i][1];
                if(xx>=0&&xx<=7&&yy<=7&&yy>=0&&board[xx][yy]=='p'){
                    cout<<"capture xx "<<xx<<"; yy "<<yy<<endl;
                    res++;
                }
            }
        }
        return res;
    }
};
