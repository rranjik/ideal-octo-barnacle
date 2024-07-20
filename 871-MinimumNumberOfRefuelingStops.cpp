class Solution {
public:
    unordered_map<int, unordered_map<int, pair<bool, int>>> c;
    pair<bool, int> dp(int sf, int i, int cs){
        if(c.find(sf)!=c.end()&&c[sf].find(i)!=c[sf].end()) return c[sf][i];
        //cout<<"sf = "<<sf<<" i = "<<i<<endl;
        
        if(target-i<=sf) return c[sf][i] = {true, 0};
        
        auto thisloc = vector<int>{i, 0};
        int nsi = sts.size();
        //for(int j = idxu+1; j<sts.size(); j++){
        //    if(sts[j][0]>i){
        //        nsi = j; 
        //        break;
        //    }
        //}
        auto nextStation = upper_bound(sts.begin()+cs, sts.end(), thisloc);
        nsi = nextStation-sts.begin();
        //cout<<"next station index = "<<nsi<<endl;
        if(nsi>=sts.size()) return c[sf][i] = {false, -1};
        auto nsd = sts[nsi][0];
        if(nsd-i>sf) return c[sf][i] = {false, -1};
        auto nsf = sts[nsi][1];
        if(nsd-i==sf) {
            auto [okay, steps] = dp(nsf, nsd, nsi+1);
            return c[sf][i] = {okay, steps+1};
        }
        
        int res = 1e9;
        auto [dontfuel, dontfuelsteps] = dp(sf-(nsd-i), nsd, nsi+1);
        auto [fuel, fuelsteps] = dp(sf-(nsd-i)+nsf, nsd, nsi+1);
        fuelsteps++;
        if(dontfuel){
            res = min(res, dontfuelsteps);
        }
        if(fuel){
            res = min(res, fuelsteps);
        }
        return c[sf][i] = {fuel|dontfuel, res};
    }
    vector<vector<int>> sts;
    int target;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stationIndex = 0;
        int fuelStock = 0;
        int n = stations.size();
        priority_queue<int> q;
        q.push(startFuel);
        int res = 0;
        while(!q.empty()){
            //wait for the largest 'reachable' station 
            auto thisStock = q.top(); q.pop();
            //fuel there so you can go longer
            fuelStock += thisStock;
            //if you're done just return
            if(fuelStock>=target) return res;
            //this means you're going to have to
            //refuel one more time at least 
            res++;
            //among all the staion that you can reach from here 
            while(stationIndex<n&&stations[stationIndex][0]<=fuelStock){
                //order them from larget to smallest 
                q.push(stations[stationIndex][1]);
                stationIndex++;
            }
        }
        return -1;
    }
};
