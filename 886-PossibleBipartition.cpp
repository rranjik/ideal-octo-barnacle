enum color{
    white,
    nexttime,
    grey,
    black
};
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjl(N+1);
        for(const auto& d : dislikes){
            adjl[d[0]].push_back(d[1]);
            adjl[d[1]].push_back(d[0]);
        }
        vector<color> vcolors(N+1, color::white);
        for(int i = 1; i<=N; i++){
            if(vcolors[i]==color::white){
                queue<int> q;
                q.push(i);
                vcolors[i] = grey;
                while(!q.empty()){
                    auto len = q.size();
                    vector<int> nexttme;
                    for(int i = 0; i<len; i++){
                        auto front = q.front(); q.pop();
                        vcolors[front] = color::black;
                        for(const auto& c : adjl[front]){
                            if(vcolors[c]==color::grey){
                                return false;
                            }else if(vcolors[c]==color::white){
                                vcolors[c] = color::nexttime;
                                nexttme.push_back(c);
                            }
                        }
                    }
                    for(const auto& n : nexttme){
                        vcolors[n] = color::grey;
                        q.push(n);
                    }
                }
            }
        }
        return true;
    }
};
