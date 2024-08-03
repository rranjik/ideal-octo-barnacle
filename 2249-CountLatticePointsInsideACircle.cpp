class Solution {
public:
    double dist(int px, int py, int cx, int cy){
        return sqrt((px-cx)*(px-cx)+(py-cy)*(py-cy));
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_map<int, unordered_set<int>> p;
        for(const auto& c : circles){
            auto ulx = c[0]-c[2];
            auto uly = c[1]+c[2];
            auto lrx = c[0]+c[2];
            auto lry = c[1]-c[2];
            for(int y = uly; y>=lry; y--){
                for(int x = ulx; x<=lrx; x++){
                    if(dist(x, y, c[0], c[1])<=c[2]){
                        p[x].insert(y);
                    }
                }
            }
        }
        int res = 0;
        for(const auto& s : p){
            res+=s.second.size();
        }
        return res;
    }
};
