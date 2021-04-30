class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        double prevFleetReach = 0;
        map<int, string> mm;
        mm.insert({2, "two"});
        mm.insert({3, "three"});
        mm.insert({1, "one"});
        for(const auto& it : mm) cout<<it.first<<" "; cout<<endl;
        map<int, double, greater<int>> m;
        for(int i = 0; i<position.size(); i++){
            auto p = position[i];
            m[p] = ((double)target-p)/speed[i];
        }
        for(auto& it : m){
            auto reachTime = it.second;
            if(prevFleetReach<reachTime){
                res++;
                prevFleetReach = reachTime;
            }
        }
        return res;
    }
};
