class Solution {
public:
    bool dfs(int x, int y, int i, const string& s){
        if(i>=s.length()) return true;
        if(x<0||y<0||x>=m||y>=n||b[x][y]!=s[i]) return false;
        b[x][y] = '-';
        auto res = false;
        res = (dfs(x+1, y, i+1, s)||dfs(x-1, y, i+1, s)||
               dfs(x, y+1, i+1, s)||dfs(x, y-1, i+1, s));
        b[x][y] = s[i];
        return res;
    }
    int m;
    int n;
    vector<vector<char>> b;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        vector<string> res;
        if(!m) return res;
        n = board[0].size();
        b = board;
        for(const auto& w : words){
            auto found = false;
            for(int i = 0; !found&&i<m; i++){
                for(int j = 0; !found&&j<n; j++){
                    if(b[i][j] == w[0]) {
                        if(dfs(i, j, 0, w)){
                            res.push_back(w);
                            found = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};
