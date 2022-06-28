class Solution {
public:
    using pii = pair<int, int>;
    void drop(vector<vector<int>>& b){
        for(int j = 0; j<n; j++){
            int count = m-1;
            for(int i = m-1; i>=0; i--){
                if(b[i][j]) b[count--][j] = b[i][j];
            }
            while(count>=0){
                b[count][j] = 0;
                count--;
            }
        }
    }
    void crush(vector<vector<int>>& b,
               vector<vector<pii>>& r, vector<vector<pii>>& c){
        for(int i =0; i<m; i++){
            for(auto& p : r[i]){
                while(p.second){
                    b[i][p.first] = 0;
                    p.first++;
                    p.second--;
                }
            }
        }
        for(int j =0; j<n; j++){
            for(auto& p : c[j]){
                while(p.second){
                    b[p.first][j] = 0;
                    p.first++;
                    p.second--;
                }
            }
        }
    }
    bool fcrush(const vector<vector<int>>& b, 
               vector<vector<pii>>& r, vector<vector<pii>>& c){
        bool stable = true;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n-1; j++){
                if(!b[i][j]) continue;
                int streak = 0;
                int sstreak = -1;
                if(b[i][j]==b[i][j+1]){
                    sstreak = j;
                    while(j<n-1&&b[i][j]==b[i][j+1]){
                        streak++;
                        j++;
                    }
                }
                if(streak>1){
                    cout<<"streak row at "<<sstreak<<" streak = "<<streak<<endl;
                    stable = false;
                    r[i].push_back({sstreak, streak+1});
                    streak=0;
                    sstreak=-1;
                }else{
                    streak=0;
                    sstreak=-1;
                }
            }
        }
        for(int j = 0; j<n; j++){
            for(int i = 0; i<m-1; i++){
                if(!b[i][j]) continue;
                int streak = 0;
                int sstreak = -1;
                if(b[i][j]==b[i+1][j]){
                    sstreak = i;
                    while(i<m-1&&b[i][j]==b[i+1][j]){
                        streak++;
                        i++;
                    }
                }
                if(streak>1){
                    cout<<"streak col at "<<sstreak<<" streak = "<<streak<<endl;
                    stable = false;
                    c[j].push_back({sstreak, streak+1});
                    streak=0;
                    sstreak=-1;
                }else{
                    streak=0;
                    sstreak=-1;
                }
            }
        }
        return stable;
    }
    int m;
    int n;
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        if(!m) return {};
        n = board[0].size();
        vector<vector<pii>> r(m);
        vector<vector<pii>> c(n);
        while(!fcrush(board, r, c)){
            cout<<"not stable "<<endl;
            for(int i = 0; i<m; i++){
                cout<<"i = "<<i;
                for(const auto& p : r[i]){
                    cout<<"; start = "<<p.first<<" streak = "<<p.second;
                }
                cout<<endl;
            }
            for(int j = 0; j<n; j++){
                cout<<"j = "<<j;
                for(const auto& p : c[j]){
                    cout<<"; start = "<<p.first<<" streak = "<<p.second;
                }
                cout<<endl;
            }
            crush(board, r, c);
            drop(board);
            cout<<"after drop start"<<endl;
            for(const auto& r : board){
                for(const auto& e : r){
                    cout<<e<<" ";
                }
                cout<<endl;
            }
            cout<<"after drop end"<<endl;
            r = vector<vector<pii>>(m);
            c = vector<vector<pii>>(n);
        }
        for(const auto& r : board){
            for(const auto& e : r){
                cout<<e<<" ";
            }
            cout<<endl;
        }
        return board;
    }
};
