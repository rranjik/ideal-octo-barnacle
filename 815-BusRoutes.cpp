class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> cantake;
        for(int i = 0; i<routes.size(); i++){
            for(const auto& s : routes[i]){
                cantake[s].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        q.push({source, 0});
        unordered_set<int> v;
        while(!q.empty()){
            auto [stop, nbus] = q.front(); q.pop();
            if(stop==target) return nbus;
            for(const auto& bus : cantake[stop]){
                for(const auto& nextstop: routes[bus]){
                    if(v.find(nextstop)==v.end()){
                        v.insert(nextstop);
                        q.push({nextstop, nbus+1});
                    }
                }
                routes[bus].clear();
            }
        }
        return -1;
    }
};
