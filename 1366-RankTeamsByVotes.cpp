class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<int, vector<int>> v;
        if(!votes.size()) return {};
        int len = votes[0].size();
        for(int i = 0; i<votes.size(); i++){
            for(int j = 0; j<votes[i].size(); j++){
                if(v.find(votes[i][j]-'A') == v.end())
                    v[votes[i][j]-'A'] = vector<int>(len);
                v[votes[i][j]-'A'][j]++;
                //for(auto it : v){
                //    cout<<"team "<<(char)('A'+it.first)<<" votes are ";
                //    for(const auto& vv : it.second) cout<<vv<<" ";
                //    cout<<endl;
                //}
                //cout<<"********************"<<endl;
            }
        }
        map<vector<int>, vector<int>, greater<vector<int>>> inv;
        for(auto it : v){
            //cout<<"team "<<it.first<<" votes are ";
            //for(const auto& vv : it.second) cout<<vv<<" ";
            //cout<<endl;
            inv[it.second].push_back(it.first);
        }
        string res;
        for(auto it : inv){
            for(const auto& t : it.second){
                res+=((char)('A'+t));
            }
        }
        //reverse(begin(res), end(res));
        return res;
    }
};
