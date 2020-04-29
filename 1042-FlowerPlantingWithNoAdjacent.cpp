class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> adjl(N);
        for(int i = 0; i<paths.size(); i++){
            adjl[paths[i][0]-1].push_back(paths[i][1]-1);
            adjl[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        cout<<"adjl prepared"<<endl;
        vector<int> res(N, -1);
        for(int i = 0; i<N; i++){
            vector<int> avail = {1, 2, 3, 4};
            for(int j = 0; j<adjl[i].size(); j++){
                avail.erase(remove_if(avail.begin(), avail.end(), [&](int x){
                    return x == res[adjl[i][j]];
                }), avail.end());
            }
            res[i] = avail[0];
        }
        return res;
    }
};
