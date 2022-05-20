namespace std{
    template <>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p)const{
            return (hash<int>()(p.first)^0x28459344)^
            (hash<int>()(p.second)^0x28459344);
        }
    };
}
class Solution {
public:
    unordered_map<pair<int, int>, int> ca;
    int dp(int i, int c){
        auto coor = pair<int, int>(i, c);
        if(ca.find(coor)!=ca.end()) return ca[coor];
        if(i<0) {
            ca[coor] = 0;
            return 0;
        }
        int res = 0;
        auto c1 = costs[i][(c+1)%3];
        auto c2 = costs[i][(c+2)%3];
        auto pc1 = dp(i-1, (c+1)%3)+c1;
        auto pc2 = dp(i-1, (c+2)%3)+c2;
        //cout<<"i = "<<i<<"; c = "<<c<<endl;
        if(pc1>pc2){
            res = pc2;
        }else res = pc1;
        ca[coor] = res;
        return res;
    }
    vector<vector<int>> costs;
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0) return 0;
        this->costs = costs;
        int c1 = dp(costs.size()-2, 1)+costs[costs.size()-1][1];
        cout<<"c1 = "<<c1<<endl;
        int c2 = dp(costs.size()-2, 2)+costs[costs.size()-1][2];
        cout<<"c2 = "<<c2<<endl;
        int c0 = dp(costs.size()-2, 0)+costs[costs.size()-1][0];
        cout<<"c0 = "<<c0<<endl;
        return min({c1, c2, c0}); 
    }
};
