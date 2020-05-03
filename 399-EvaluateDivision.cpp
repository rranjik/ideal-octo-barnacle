class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> sym;
        int n = 0;
        for(const auto& eq : equations){
            for(int i = 0; i<2; i++){
                if(sym.find(eq[i])==sym.end()){
                    sym[eq[i]] = n++;
                }
            }
        }
        vector<vector<double>> adjm(n, vector<double>(n, numeric_limits<double>::infinity()));
        for(int i = 0; i<equations.size(); i++){
            adjm[sym[equations[i][0]]][sym[equations[i][1]]] = values[i];
            adjm[sym[equations[i][1]]][sym[equations[i][0]]] = (1/values[i]);
            adjm[sym[equations[i][0]]][sym[equations[i][0]]] = (1);
            adjm[sym[equations[i][1]]][sym[equations[i][1]]] = (1);
        }
        for(int k = 0; k<n; k++){
            for(int j = 0; j<n; j++){
                for(int i = 0; i<n; i++){
                    //if(adjm[i][k]!=numeric_limits<double>::infinity()&&adjm[k][j]!=numeric_limits<double>::infinity()){
                        if(adjm[i][j]>(adjm[i][k]*adjm[k][j])){
                            adjm[i][j]=(adjm[i][k]*adjm[k][j]);
                        }
                    //}
                }
            }
        }
        vector<double> res;
        for(int i = 0; i<queries.size(); i++){
            if(sym.find(queries[i][0])==sym.end()||sym.find(queries[i][1])==sym.end()){
                res.push_back(-1);
            }else {
                //res.push_back(-1);
                res.push_back((adjm[sym[queries[i][0]]][sym[queries[i][1]]]==numeric_limits<double>::infinity())?(-1):(adjm[sym[queries[i][0]]][sym[queries[i][1]]]));
            }
        }
        return res;
    }
};
