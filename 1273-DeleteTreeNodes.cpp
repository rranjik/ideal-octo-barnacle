class Solution {
public:
    unordered_map<int, vector<int>> adjl;
    unordered_map<int, int> val;
    unordered_map<int, int> subsz;
    unordered_map<int, int> sum;
    //subtree sum, # of nodes
    pair<int, int> dfs(int src){
        int substreesz{};
        int suminclusive{};
        int children{};
        for(const auto& c : adjl[src]){
            auto thischild = dfs(c);
            suminclusive+=thischild.first;
            if(thischild.first) children+=thischild.second;
        }
        suminclusive+=val[src];
        sum[src] = suminclusive;
        subsz[src] = substreesz;
        if(suminclusive) children+=1;
        else children = 0;
        return {suminclusive, children};
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        for(int i = 0; i<parent.size(); i++){
            adjl[parent[i]].push_back(i);
            val[i] = value[i];
        }
        auto res = dfs(0);
        if(res.first) return res.second;
        else return 0;
    }
};
