class Solution {
public:
    bool squareIsWhite(string c) {
        vector<vector<bool>> b(8, vector<bool>(8));
        bool last = true;
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                b[i][j] = !last;
                last= !last;
            }
            last=!last;
        }
        return b[c[0]-'a'][c[1]-'1'];
    }
};
