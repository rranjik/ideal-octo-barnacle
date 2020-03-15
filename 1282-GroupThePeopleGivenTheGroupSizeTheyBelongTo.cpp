class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<vector<int>>> r = vector<vector<vector<int>>>(501, vector<vector<int>>());
        int n = 0;
        for(const auto& gs: groupSizes){
            
            if(r[gs].size()==0){
                vector<int> group;
                group.push_back(n);
                r[gs].push_back(group);
            }
            else{
                if(r[gs][r[gs].size()-1].size()==gs){
                    vector<int> group;
                    group.push_back(n);
                    r[gs].push_back(group);
                }
                else {
                    r[gs][r[gs].size()-1].push_back(n);
                }
            }
            n++;
        }
        vector<vector<int>> res;
        for(const auto& groups : r){
            for(const auto& group: groups){
                res.push_back(group);
            }
        }
        return res;
    }
};
