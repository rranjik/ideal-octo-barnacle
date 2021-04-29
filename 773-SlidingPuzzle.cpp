class Solution {
public:
    string b2s(vector<vector<int>> b){
        string res;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<3; j++){
                res+=to_string(b[i][j]);
            }
        }
        return res;
    }
    vector<vector<int>> s2b(string s){
        vector<vector<int>> res(2, vector<int>(3));
        res[0][0] = s[0]-'0';
        res[0][1] = s[1]-'0';
        res[0][2] = s[2]-'0';
        res[1][0] = s[3]-'0';
        res[1][1] = s[4]-'0';
        res[1][2] = s[5]-'0';
        return res;
    }
    string r = "123450";
    unordered_set<string> seen;
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> b;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<3; j++){
                if(board[i][j]) b.push_back(board[i][j]);
            }
        }
        int inv = 0;
        for(int i = 0; i<4; i++){
            for(int j = i+1; j<5; j++){
                if(b[i]>b[j]) inv++;
            }
        }
        if(inv%2) return -1;
        queue<string> q;
        q.push(b2s(board));
        int level = 0;
        while(!q.empty()){
            int len = q.size();
            for(int k = 0; k<len; k++){
                auto state = q.front();
                cout<<"examining "<<state<<endl;
                q.pop();
                if(state == r) return level;
                auto bstate = s2b(state);
                int zx = -1; int zy = -1;
                for(int i = 0; i<2; i++){
                    for(int j = 0; j<3; j++){
                        if(!bstate[i][j]) {zx = i; zy = j;}
                    }
                }
                if(zx-1>=0){
                    auto bc = bstate;
                    swap(bc[zx-1][zy], bc[zx][zy]);
                    auto nstate = b2s(bc);
                    if(seen.find(nstate)==seen.end()){
                        seen.insert(nstate);
                        cout<<" entering "<<nstate<<endl;
                        q.push(nstate);
                    }
                }
                if(zx+1<2){
                    auto bc = bstate;
                    swap(bc[zx+1][zy], bc[zx][zy]);
                    auto nstate = b2s(bc);
                    if(seen.find(nstate)==seen.end()){
                        seen.insert(nstate);
                        cout<<" entering "<<nstate<<endl;
                        q.push(nstate);
                    }
                }
                if(zy+1<3){
                    auto bc = bstate;
                    swap(bc[zx][zy+1], bc[zx][zy]);
                    auto nstate = b2s(bc);
                    if(seen.find(nstate)==seen.end()){
                        seen.insert(nstate);
                        cout<<" entering "<<nstate<<endl;
                        q.push(nstate);
                    }
                }
                if(zy-1>=0){
                    auto bc = bstate;
                    swap(bc[zx][zy-1], bc[zx][zy]);
                    auto nstate = b2s(bc);
                    if(seen.find(nstate)==seen.end()){
                        seen.insert(nstate);
                        cout<<" entering "<<nstate<<endl;
                        q.push(nstate);
                    }
                }
            }
            level++;
        }
        return 0;
    }
};
