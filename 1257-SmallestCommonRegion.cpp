class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> p;
        for(int i = 0; i<regions.size(); i++){
            for(int j = 1; j<regions[i].size(); j++){
                p.insert({regions[i][j], regions[i][0]});
            }
        }
        vector<string> r1;
        vector<string> r2;
        while(p.find(region1)!=p.end()){
            r1.push_back(region1);
            region1 = p[region1];
        }
        r1.push_back(region1);
        while(p.find(region2)!=p.end()){
            r2.push_back(region2);
            region2 = p[region2];
        }
        r2.push_back(region2);
        for(int i = 0; i<r1.size(); i++){
            if(find(begin(r2), end(r2), r1[i])!=r2.end())
                return r1[i];
        }
        return string();
    }
};
