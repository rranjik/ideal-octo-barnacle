class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjm(n, vector<int> (n, 1000000));
        for(const auto& e : edges){
            adjm[e[0]][e[1]] = e[2];
            adjm[e[1]][e[0]] = e[2];
        }
        for(const auto& c : adjm){
            for(const auto& ac : c){
                cout<<ac<<" ";
            }
            cout<<endl;
        }
        cout<<"****************"<<endl;
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(i!=j){
                    if(adjm[i][k]+adjm[k][j]<adjm[i][j]){
                        adjm[i][j] = adjm[i][k]+adjm[k][j];
                    }
                    }
                }
            }
        }
        for(const auto& c : adjm){
            for(const auto& ac : c){
                cout<<ac<<" ";
            }
            cout<<endl;
        }
        vector<int> res;
        int minic = numeric_limits<int>::max();
        for(int i = 0; i<n; i++){
            int nc = 0;
            for(int j = 0; j<n; j++){
                if(adjm[i][j]<=distanceThreshold){
                    nc++;
                }
            }
            if(nc<minic){
                minic = nc;
                res.clear();
                res.push_back(i);
            }else if(nc==minic){
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end(), greater<int>());
        cout<<"rssssssss"<<endl;
        for(const auto& rr : res){
            cout<<rr<<" ";
        }
        return res[0];
    }
};
