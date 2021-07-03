class Solution {
public:
    int winner(const vector<vector<int>>& b){
        for(int i = 0; i<3; i++){
            if(b[i][0]==b[i][1]&&b[i][1]==b[i][2]) return b[i][0];
        }
        for(int j = 0; j<3; j++){
            if(b[0][j]==b[1][j]&&b[0][j]==b[2][j]) return b[0][j];
        }
        if(b[0][0]==b[1][1]&&b[0][0]==b[2][2]) return b[0][0];
        if(b[0][2]==b[1][1]&&b[1][1]==b[2][0]) return b[1][1];
        return {};
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> b(3, vector<int>(3));
        int toPlay = 1;
        for(const auto& m :moves){
            b[m[0]][m[1]] = toPlay;
            auto w = winner(b);
            if(w) return w==1?"A":"B";
            toPlay = toPlay==1?2:1;
        }
        for(const auto& r : b){
            for(const auto& n : r) {
                if(!n) return "Pending";
            }
        }
        return "Draw";
    }
};
