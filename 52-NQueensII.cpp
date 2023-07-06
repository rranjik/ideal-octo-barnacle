class Solution {
public:
    //imagine that you have two chessboards
    // doing main diagonals is easy
    //because sum i+j is constant
    //     \? \? /?
    //  \? /0 /1 /2 /3 
    //  \?00 01 02 03 /4
    //  \?10 11 12 13 /5 
    //  \?20 21 22 23 /6 
    //    30 31 32 33 
    //but the sub diagonals are hard to identify
    //so imagine that the other chessboard has the
    //rows inverted
    //calculating main diags here is straighforward
    //so imagine we place the queen on here too
    //so it's just matter of translating between the two
    //  30 31 33 34
    //  20 21 23 24
    //  10 11 12 13
    //  00 01 02 03
    //placing a queen at 11 of the first board is the same
    //as placing one at 21 of the second board
    //  00 01 02 03 || 30 31 33 34
    //  10 ** 12 13 || 20 ** 23 24
    //  20 21 22 23 || 10 11 12 13
    //  30 31 32 33 || 00 01 02 03
    int dfs(const int& n,
            int r, 
            vector<int>& cols, 
            vector<int>& diags,
            vector<int>& idiags){
        //cout<<"r = "<<r<<" cols ";
        //for(const auto& c : cols) cout<<c<<" ";
        //cout<<" diags = ";
        //for(const auto& d : diags) cout<<d<<" ";
        //cout<<" idiags = ";
        //for(const auto& d : idiags) cout<<d<<" ";
        //cout<<endl;
        if(r==n) return 1;
        int res = 0;
        for(int i = 0; i<n; i++){
            auto d = i+r;
            //inverted row
            auto ir = n-r-1;
            //inverse diagonal
            auto id = ir+i;
            //cout<<" i = "<<i<<" d = "<<d<<endl;
            if(!cols[i]&&!diags[d]&&!idiags[id]){
                cols[i] = 1;
                diags[d] = 1;
                idiags[id] = 1;
                res += dfs(n, r+1, cols, diags, idiags);
                cols[i] = 0;
                diags[d] = 0;
                idiags[id] = 0;
            }
        }
        return res;
    }
    int totalNQueens(int n) {
        vector<int> cols(n);
        vector<int> diags(2*n-1);
        vector<int> idiags(2*n-1);
        auto res = dfs(n, 0, cols, diags, idiags);
        return res;
    }
};
