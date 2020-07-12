class Solution {
public:
    int w;
    int h;
    bool search(int x, int y, const string& s, 
                int i, vector<vector<char>>& b){
        if(i==s.length()) { 
            cout<<"x = "<<x<<"; y = "<<y<<endl;
            return true;
        }
        if(x<0||x>=h||y<0||y>=w) return false;
        if(b[x][y]!=s[i]) return false;
        b[x][y] = '-';
        int res = false;
        res = search(x-1, y, s, i+1, b) || search(x+1, y, s, i+1, b)
            ||search(x, y-1, s, i+1, b) || search(x, y+1, s, i+1, b);
        //bool up = search(x-1, y, s, i+1, b); 
        //if(up) {
        //    cout<<"up x = "<<x<<"; y = "<<y<<endl;
        //}
        //bool bot = search(x+1, y, s, i+1, b);
        //if(bot) {
        //    cout<<"bot x = "<<x<<"; y = "<<y<<endl;
        //}
        //bool left = search(x, y-1, s, i+1, b);
        //if(left) {
        //    cout<<"left x = "<<x<<"; y = "<<y<<endl;
        //}
        //bool right = search(x, y+1, s, i+1, b);
        //if(right) {
        //    cout<<"right x = "<<x<<"; y = "<<y<<endl;
        //}
        b[x][y] = s[i];
        return res; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        w = board[0].size();
        cout<<"h = "<<h<<"; w = "<<w<<endl;
        for(int i = 0; i<h; i++){
            for(int j = 0; j<w; j++){
               if(search(i, j, word, 0, board)){
                   cout<<"i = "<<i<<"; j = "<<j<<endl;
                   return true;
               } 
            }
        }
        return false;
    }
};
