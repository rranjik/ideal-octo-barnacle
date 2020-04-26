class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> adjm(N+1, vector<int>(N+1, 0));
        for(const auto& t :trust){
            adjm[t[0]][t[1]] = 1;
        }
        //for(const auto& o : adjm){
        //    for(const auto& r : o){
        //        cout<<r<<" ";
        //    }
        //    cout<<endl;
        //}
        auto tj = -1;
        for(int i = 1; i<=N; i++){
            auto in = 0;
            for(int j = 1; j<=N; j++){
                in+=adjm[j][i];
            }
            cout<<"i = "<<i<<"; in = "<<in<<endl;
            if(in==N-1&&!accumulate(adjm[i].begin(), adjm[i].end(), 0)){
                if(tj!=-1) return false;
                tj = i;
            }
        }
        return tj;
    }
};
